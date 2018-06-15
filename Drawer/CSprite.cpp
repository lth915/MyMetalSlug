#include "stdafx.h"
#include "CSprite.h"

CSprite::CSprite()
{
	m_updateCounter.SetLimit(CCounter::SecondToFrame(0.3));
	m_currentID = SPRITE_ID::RIGHT_IDEL;
}

void CSprite::Load(LPCSTR szAddress)
{
	m_data = CDataLoader::Get()->GetData(szAddress);
}

void CSprite::ChangeSprite(SPRITE_ID id, bool connection)
{
	for (int i = 0; i < m_data.divine; ++i)
	{
		m_position[i] = m_data.positions.find(id)->second[i];
		m_size[i] = m_data.sizes.find(id)->second[i];

		if (!connection) m_index[i] = m_position[i];
	}
}

void CSprite::Draw(HDC hdc, const Vector2d & position, const Vector2d & size)
{
	for (int i = 0; i < m_data.divine; ++i)
	{
		m_data.image.TransparentBlt(hdc, position.x, position.y, size.x, size.y,
			m_position[i].x + m_size[i].x * m_index[i].x,
			m_position[i].y + m_size[i].y * m_index[i].y,
			m_size[i].x, m_size[i].y, MAGENTA);
	}
}

void CSprite::Update()
{
	m_updateCounter.Increase();

	if (m_updateCounter.isLimit())
	{
		for (int i = 0; i < m_data.divine; ++i) {
			++m_index[i].x;

			Point2D border = m_data.border.find(m_currentID)->second[i];
			if (m_index[i].x > border.x)
				m_index[i].x = m_position[i].x;
		}
		m_updateCounter.ResetCount();
	}
}




