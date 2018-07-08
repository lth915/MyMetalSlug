#pragma once
#include "CPlayable.h"

class CMarco :
	public CPlayable
{
public:
	CMarco();
	~CMarco();

	virtual void Update() { m_sprite->Update(); }
	virtual void Draw(HDC hdc) { m_sprite->Draw(hdc, m_position); }

	virtual bool IsDelete() { return false; }
};

