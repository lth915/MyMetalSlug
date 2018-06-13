#include "stdafx.h"
#include "CPlayerState.h"


CPlayerState::CPlayerState()
{
}


CPlayerState::~CPlayerState()
{
}

void CIdleState::Enter(CPlayable * player)
{
}

void CIdleState::Exit(CPlayable * player)
{
}

CPlayerState * CIdleState::HandleInput(CPlayable * player, KEY_INPUT input)
{
	return nullptr;
}

CMoveState::CMoveState(WAY way, GUN_TYPE type)
{
}

void CMoveState::Enter(CPlayable * player)
{
}

void CMoveState::Exit(CPlayable * player)
{
}

CPlayerState * CMoveState::HandleInput(CPlayable * player, KEY_INPUT input)
{
	return nullptr;
}

CAttackState::CAttackState(WAY way, GUN_TYPE type)
{
}

void CAttackState::Enter(CPlayable * player)
{
}

void CAttackState::Exit(CPlayable * player)
{
}

CPlayerState * CAttackState::HandleInput(CPlayable * player, KEY_INPUT input)
{
	return nullptr;
}

CMoveAttackState::CMoveAttackState(GUN_TYPE type)
{
}

void CMoveAttackState::Enter(CPlayable * player)
{
}

void CMoveAttackState::Exit(CPlayable * player)
{
}

CPlayerState * CMoveAttackState::HandleInput(CPlayable * player, KEY_INPUT input)
{
	return nullptr;
}
