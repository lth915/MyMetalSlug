#pragma once
#include "CScene.h"
#include "CCounter.h"
#include "CMarco.h"

#define TEST_NUM  7

class CTestScene :
	public CScene
{
public:
	CTestScene();
	~CTestScene();

	void Update() override;
	void Draw(HDC hdc) override;
	void ProcessInput() override;

	LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
private:

	void BuildObjects() override {}
	void ReleaseObjects() override {}

	CImage m_image;
	
	CCounter m_counter[TEST_NUM];
	int m_pos[TEST_NUM];
	
	Point2D m_startPos[TEST_NUM];
	Point2D m_sizes[TEST_NUM];
	int m_divine[TEST_NUM];

	CPlayable *m_player;
};

