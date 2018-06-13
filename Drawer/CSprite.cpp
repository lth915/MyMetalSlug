#include "stdafx.h"
#include "CSprite.h"

void CSprite::Load(LPCSTR szAddress)
{
}

void CSprite::ChangeSprite(SPRITE_ID id)
{
	m_position = m_positions.find(id)->second;
	m_size = m_sizes.find(id)->second;
}




