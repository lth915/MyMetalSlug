#include "stdafx.h"
#include "CJson.h"

using namespace rapidjson;

CJson::CJson()
{
}

CJson::~CJson()
{
}

void CJson::Load(LPSTR szAddress, IO_TYPE type)
{
	fopen_s(&m_file,"szAddress", "rb"); // non-Windows use "r"
	rapidjson::FileReadStream fileStream(m_file, m_readBuffer, sizeof(m_readBuffer));
	m_document.ParseStream(fileStream);	// == m_document.Parse(fileStream);
	fclose(m_file);
}

void CJson::Read()
{	
	
}

void CJson::Write()
{
}

void CJson::Close()
{
}

void CJson::DataLoad(LPCSTR szAddress, DATA_NAME name, map<DATA_NAME,SpriteFileData>& datas)
{
	m_file = fopen(szAddress, "rb"); // non-Windows use "r"
	m_readBuffer[1000];
	FileReadStream is(m_file, m_readBuffer, sizeof(m_readBuffer));

	m_document.ParseStream(is);	//==d.Parse(is);
	fclose(m_file);

	SpriteFileData inputData;
	LPCSTR key = "RIGHT_IDLE";
	SPRITE_ID id = SPRITE_ID::RIGHT_IDEL;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}

	key = "RIGHT_UP"; id = SPRITE_ID::RIGHT_UP;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}

	key = "RIGHT_UP_ATTACK"; id = SPRITE_ID::RIGHT_UP_ATTACK;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_UP_ATTACK_INTERVAL"; id = SPRITE_ID::RIGHT_UP_ATTACK_INTERVAL;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_ATTACK"; id = SPRITE_ID::RIGHT_ATTACK;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_ATTACK_INTERVAL"; id = SPRITE_ID::RIGHT_ATTACK_INTERVAL;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_JUMP"; id = SPRITE_ID::RIGHT_JUMP;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_JUMP_ATTACK"; id = SPRITE_ID::RIGHT_JUMP_ATTACK;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_JUMP_ATTACK_INTERVAL"; id = SPRITE_ID::RIGHT_JUMP_ATTACK_INTERVAL;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_SWING_1"; id = SPRITE_ID::RIGHT_SWING_1;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_SWING_2"; id = SPRITE_ID::RIGHT_SWING_2;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	key = "RIGHT_THROW"; id = SPRITE_ID::RIGHT_THROW;
	if (m_document.HasMember(key)) {
		FillStruct(key, inputData, id);
	}
	datas.emplace(make_pair(name, inputData));
}

void CJson::FillStruct(LPCSTR key, SpriteFileData& data, SPRITE_ID id)
{
	Point2D tempData; 
	vector<Point2D> v;

	tempData = ReadArray(key, 0, 1);
	data.position.emplace(make_pair(id, tempData));
	v.clear();
	
	tempData = ReadArray(key, 2, 3);
	data.sizes.emplace(make_pair(id, tempData));
	
	data.border.emplace(make_pair(id, ReadInt(key, 4)));
}

Point2D CJson::ReadArray(LPCSTR key, int indexFirst, int indexNext)
{
	Point2D retValue;
	retValue.x = m_document[key].GetArray()[indexFirst].GetInt();
	retValue.y = m_document[key].GetArray()[indexNext].GetInt();
	return retValue;
}

int CJson::ReadInt(LPCSTR key, int index)
{
	return m_document[key].GetArray()[index].GetInt();
}
