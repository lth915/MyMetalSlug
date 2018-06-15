#include "stdafx.h"
#include "CDataLoader.h"

// 인스턴스를 초기화 해줍니다.
SINGLETON_IMPL(CDataLoader);

CDataLoader::~CDataLoader()
{
}

void CDataLoader::Load(LPCTSTR address, DATA_NAME dataName)
{
	if (m_datas.find(dataName) != m_datas.end())
		return;
//	m_datas.emplace(make_pair(dataName, CJson::Read(address));
}

SpriteFileData CDataLoader::GetData(DATA_NAME dataName)
{
	assert(m_datas.find(dataName) != m_datas.end() && "존재하지 않는 정보입니다.");
	return m_datas.find(dataName)->second;
}
