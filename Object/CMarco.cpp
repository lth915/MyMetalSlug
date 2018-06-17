#include "stdafx.h"
#include "CMarco.h"


CMarco::CMarco()
{
	m_sprite = new CSprite("PLAYER_MARCO");
	m_sprite->Load("resource/marco_data.json");
}


CMarco::~CMarco()
{
}
