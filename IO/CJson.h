#pragma once

#include "CIOManager.h"
#include "../json/include/rapidjson/document.h"
#include "../json/include/rapidjson/writer.h"
#include "../json/include/rapidjson/prettywriter.h"
#include "../json/include/rapidjson/stringbuffer.h"
#include "../json/include/rapidjson/filereadstream.h"
#include "../json/include/rapidjson/filewritestream.h"

#include "CDataLoader.h"

class CJson : public CIOManager
{
public:
	CJson();
	~CJson();

	virtual void Load(LPSTR szAddress, IO_TYPE type);

	virtual void Read();	

	virtual void Write();

	virtual void Close();

	void DataLoad(LPCSTR szAddress, DATA_NAME name, map<DATA_NAME,SpriteFileData>& datas);
private:
	void FillStruct(LPCSTR key, SpriteFileData& data, SPRITE_ID id);
	Point2D ReadArray(LPCSTR key, int indexFirst, int indexNext);
	int ReadInt(LPCSTR key, int index);

	FILE * m_file;	
	char m_readBuffer[1000];
	rapidjson::Document m_document;
};

