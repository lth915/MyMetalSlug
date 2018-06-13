#pragma once
#include "CPlayable.h"

class CMarco :
	public CPlayable
{
public:
	CMarco();
	~CMarco();

	virtual void Update() {}
	virtual void Draw(HDC hdc) {}

	virtual bool IsDelete() { return false; }
};

