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
}

SpriteFileData CDataLoader::GetData(DATA_NAME dataName)
{
	assert(m_datas.find(dataName) != m_datas.end() && "�������� �ʴ� �����Դϴ�.");
	return m_datas.find(dataName)->second;
}
