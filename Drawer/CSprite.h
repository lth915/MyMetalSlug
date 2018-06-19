#pragma once
#include "CCounter.h"
#include "CDataLoader.h"

#define MAGENTA RGB(255,0,255)

class CSprite
{
public:
	CSprite(DATA_NAME name);
	void Load(LPCSTR dataFileName, LPCTSTR imageFileName);
	void ChangeSprite(SPRITE_ID id, bool connection);
	void Draw(HDC hdc, const Vector2d & position, const Vector2d & size);
	void Draw(HDC hdc, const Vector2d & position);

	void Update();

private:
	CImage m_image;
	SpriteFileData m_data;

	Point2D m_position;
	Point2D m_size;
	int m_index;

	SPRITE_ID m_currentID;
	CCounter m_updateCounter;

	DATA_NAME m_name;
};


