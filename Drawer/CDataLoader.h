#pragma once
#include "Singleton.h"

enum class SPRITE_ID : int
{
	LEFT_IDEL,
	RIGHT_IDEL,

	LEFT_MOVE,
	RIGHT_MOVE,
	UP_MOVE,
	DOWN_MOVE,

	LEFT_JUMP,
	RIGHT_JUMP,

	LEFT_ATTACK,
	RIGHT_ATTACK,
	UP_ATTACK,
	DOWN_ATTACK,

	LEFT_MOVE_ATTACK,
	RIGHT_MOVE_ATTACK,
	UP_MOVE_ATTACK,
	DOWN_MOVE_ATTACK,

	LEFT_DIE,
	RIGHT_DIE,
};

struct SpriteFileData
{
	map<SPRITE_ID, vector<Point2D>> positions;
	map<SPRITE_ID, vector<Point2D>> sizes;
	map<SPRITE_ID, vector<Point2D>> border;
	CImage image;
	int divine;
};

using DATA_NAME = string;

class CDataLoader : public Singleton<CDataLoader>
{
	SINGLETON_DECL(CDataLoader);
	map<DATA_NAME, SpriteFileData> m_datas;

public:
	~CDataLoader();
	void Load(LPCTSTR address, DATA_NAME imageName);
	SpriteFileData GetData(DATA_NAME dataName);
};