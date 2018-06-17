#include "stdafx.h"
#include "CDataLoader.h"
#include "CJson.h"

CDataLoader* CDataLoader::instance = nullptr;

CDataLoader::~CDataLoader()
{
}

void CDataLoader::Load(LPCSTR address, DATA_NAME dataName)
{
	if (m_datas.find(dataName) != m_datas.end())
		return;
	SAFE_DELETE(m_jsonReader);

	m_jsonReader = new CJson();
	m_jsonReader->DataLoad(address, dataName, m_datas);
	m_jsonReader->ImageLoad(dataName, m_images);
}

SpriteFileData CDataLoader::GetData(DATA_NAME dataName)
{
	assert(m_datas.find(dataName) != m_datas.end() && "존재하지 않는 정보입니다.");
	return m_datas.find(dataName)->second;
}

CImage CDataLoader::GetImage(DATA_NAME name)
{
	assert(m_images.find(name) != m_images.end() && "존재하지 않는 정보입니다.");
	return m_images.find(name)->second;
}
