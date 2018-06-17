#pragma once
enum class SPRITE_ID 
{
	LEFT_IDEL,
	LEFT_MOVE,
	LEFT_JUMP,
	LEFT_ATTACK,
	LEFT_MOVE_ATTACK,
	LEFT_DIE,

	RIGHT_IDEL,
	RIGHT_UP,
	RIGHT_UP_ATTACK,
	RIGHT_UP_ATTACK_INTERVAL,
	RIGHT_ATTACK,
	RIGHT_ATTACK_INTERVAL,
	RIGHT_JUMP,
	RIGHT_JUMP_ATTACK,
	RIGHT_JUMP_ATTACK_INTERVAL,
	RIGHT_SWING_1,
	RIGHT_SWING_2,
	RIGHT_THROW,

	UP_MOVE,
	DOWN_MOVE,
	UP_ATTACK,
	DOWN_ATTACK,
	UP_MOVE_ATTACK,
	DOWN_MOVE_ATTACK,
};

struct SpriteFileData
{
	map<SPRITE_ID, vector<Point2D>> positions;
	map<SPRITE_ID, vector<Point2D>> sizes;
	map<SPRITE_ID, vector<int>> border;
	int divine = 1;
};

using DATA_NAME = string;
class CJson;

class CDataLoader 
{	
public:
	static CDataLoader* Get() { if (!instance) instance = new CDataLoader(); return instance; }
	
	~CDataLoader();
	void Load(LPCSTR address, DATA_NAME imageName);
	SpriteFileData GetData(DATA_NAME dataName);
	CImage GetImage(DATA_NAME name);

private:
	map<DATA_NAME, SpriteFileData> m_datas;
	map<DATA_NAME, CImage> m_images;
	CJson*	m_jsonReader;
	DATA_NAME m_lastData;

	static CDataLoader* instance;
};