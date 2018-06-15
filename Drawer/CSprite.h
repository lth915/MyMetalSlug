#pragma once
#include "CCounter.h"
#include "CDataLoader.h"

#define MAGENTA RGB(255,0,255)

class CSprite
{
public:
	CSprite();
	void Load(LPCSTR szAddress);
	void ChangeSprite(SPRITE_ID id, bool connection);
	void Draw(HDC hdc, const Vector2d & position, const Vector2d & size);

	void Update();

private:
	SpriteFileData m_data;

	vector<Point2D> m_position;
	vector<Point2D> m_size;
	vector<Point2D> m_index;

	SPRITE_ID m_currentID;
	CCounter m_updateCounter;
};


