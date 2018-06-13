#pragma once
#include "CGameObject.h"
class CPlayable :
	public CGameObject
{
public:
	CPlayable();
	~CPlayable();

	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;

	virtual bool IsDelete() = 0;
};

