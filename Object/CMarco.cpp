#include "stdafx.h"
#include "CMarco.h"


CMarco::CMarco()
{
	m_sprite = new CSprite("PLAYER_MARCO");
	m_sprite->Load("resource/marco_data.json", TEXT("resource/marco_2.png"));

	m_position = { 200,300 };
}


CMarco::~CMarco()
{
}
