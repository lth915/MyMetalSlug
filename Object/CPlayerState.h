#pragma once

class CPlayable;
enum class GUN_TYPE : int
{
	Basic = 0,
};

class CPlayerState
{
public:
	CPlayerState();
	~CPlayerState();

	virtual void Enter(CPlayable * player) = 0;
	virtual void Exit(CPlayable * player) = 0;

	virtual CPlayerState* HandleInput(CPlayable * player, KEY_INPUT input) = 0;
};

class CIdleState : public CPlayerState
{
public:
	void Enter(CPlayable * player) override;
	void Exit(CPlayable * player) override;

	CPlayerState* HandleInput(CPlayable * player, KEY_INPUT input) override;
};

class CMoveState : public CPlayerState
{
public:
	CMoveState(WAY way, GUN_TYPE type = GUN_TYPE::Basic);

	void Enter(CPlayable * player) override;
	void Exit(CPlayable * player) override;

	CPlayerState* HandleInput(CPlayable * player, KEY_INPUT input) override;
};

class CAttackState : public CPlayerState
{
public:
	CAttackState(WAY way, GUN_TYPE type = GUN_TYPE::Basic);

	void Enter(CPlayable * player) override;
	void Exit(CPlayable * player) override;

	CPlayerState* HandleInput(CPlayable * player, KEY_INPUT input) override;
};

class CMoveAttackState : public CPlayerState
{
public:
	CMoveAttackState(GUN_TYPE type = GUN_TYPE::Basic);

	void Enter(CPlayable * player) override;
	void Exit(CPlayable * player) override;

	CPlayerState* HandleInput(CPlayable * player, KEY_INPUT input) override;
};