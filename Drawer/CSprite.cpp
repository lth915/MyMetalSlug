#include "stdafx.h"
#include "CSprite.h"

CSprite::CSprite(DATA_NAME name)
{
	m_updateCounter.SetLimit(CCounter::SecondToFrame(0.15));
	m_currentID = SPRITE_ID::RIGHT_ATTACK;

	m_name = name;
}

void CSprite::Load(LPCSTR dataFileName, LPCTSTR imageFileName)
{
	CDataLoader::Get()->Load(dataFileName, m_name);

	m_data = CDataLoader::Get()->GetData(m_name);
	m_image.Load(imageFileName);
	
	m_position = m_data.position.find(m_currentID)->second;
	m_size = m_data.sizes.find(m_currentID)->second;
	m_index = 0;
}

void CSprite::ChangeSprite(SPRITE_ID id, bool connection)
{
	m_position = m_data.position.find(m_currentID)->second;
	m_size = m_data.sizes.find(m_currentID)->second;
	m_index = 0;
}

void CSprite::Draw(HDC hdc, const Vector2d & position, const Vector2d & size)
{
	m_image.TransparentBlt(hdc, position.x, position.y, size.x, size.y,
		m_position.x + m_size.x * m_index,
		m_position.y + m_size.y,
		m_size.x, m_size.y, MAGENTA);
}

void CSprite::Draw(HDC hdc, const Vector2d & position)
{
	m_image.TransparentBlt(hdc, position.x, position.y, 
		m_size.x * 2, m_size.y * 2,
		m_position.x + m_size.x * m_index, m_position.y,
		m_size.x, m_size.y, MAGENTA);
}

void CSprite::Update()
{
	m_updateCounter.Increase();

	if (m_updateCounter.isLimit())
	{
		++m_index;

		int border = m_data.border.find(m_currentID)->second;

		if (m_index > border - 1)
			m_index = 0;
		m_updateCounter.ResetCount();
	}
}




