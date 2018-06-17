#pragma once
#include "CCounter.h"
#include "CDataLoader.h"

#define MAGENTA RGB(255,0,255)

class CSprite
{
public:
	CSprite(DATA_NAME name);
	void Load(LPCSTR szAddress);
	void ChangeSprite(SPRITE_ID id, bool connection);
	void Draw(HDC hdc, const Vector2d & position, const Vector2d & size);
	void Draw(HDC hdc, const Vector2d & position);

	void Update();

private:
	CImage m_image;
	SpriteFileData m_data;

	vector<Point2D> m_position;
	vector<Point2D> m_size;
	vector<Point2D> m_index;

	SPRITE_ID m_currentID;
	CCounter m_updateCounter;

	DATA_NAME m_name;
};


