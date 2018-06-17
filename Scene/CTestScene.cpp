#include "stdafx.h"
#include "CTestScene.h"


CTestScene::CTestScene()
{
	m_player = new CMarco();
}


CTestScene::~CTestScene()
{
}

void CTestScene::Update()
{ 
	m_player->Update();
}

void CTestScene::Draw(HDC hdc)
{
	m_player->Draw(hdc);
}

void CTestScene::ProcessInput()
{
}

LRESULT CTestScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
