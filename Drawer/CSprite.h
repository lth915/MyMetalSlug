#pragma once

enum class SPRITE_ID : int
{

};

class CSprite
{
public:
	void Load(LPCSTR szAddress);
	void ChangeSprite(SPRITE_ID id);

private:
	CImage m_image;

	map<SPRITE_ID, Point2D> m_positions;
	map<SPRITE_ID, Point2D> m_sizes;

	Point2D m_position;
	Point2D m_size;
};


