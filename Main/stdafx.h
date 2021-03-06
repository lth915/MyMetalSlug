// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 정의
using Viewport = RECT;

/* 리턴값z
0x0000 : 이전에 눌린 적이 없고 호출 시점에도 눌리지 않은 경우
0x0001 : 이전에 눌린 적이 있고 호출 시점에는 눌리지 않은 경우
0x8000 : 이전에 눌린 적이 없고 호출 시점에는 눌린 경우
0x8001 : 이전에 눌린 적이 있고 호출 시점에는 눌린 경우 */
#define IS_KEY_DOWN(key) (GetAsyncKeyState(key) & 0x8000) ? 1 : 0
#define IS_KEY_UP(key) (GetAsyuncKeyState(key) & 0x8000) ? 0 : 1	

#define CLIENT_WIDTH   450
#define CLIENT_HEIGHT  850

#define FRAME_PER_SECOND 80
#define UPDATE_FPS 1.0f / FRAME_PER_SECOND

#define SAFE_DELETE(T) if(T) delete T; T = nullptr;
//
// 디버그 모드인 경우, 텍스트 형식에 맞게 윈도우 하위 창으로 콘솔을 사용
#ifdef _DEBUG		
	#ifdef UNICODE
		#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
	#else
		#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
	#endif
#endif	


/*
180 degree = PI radian
1 degree = PI / 180 radain
x degree = x * PI / 180 radian

180 / PI degree = 1radain
180 / Pi * x = x radian
*/
#define ANGLE 360.0f
#define PI 3.141592f
#define DegToRad(degree) degree * PI / 180.0f
#define RadToDeg(radian) radain * 180.0f / PI

// 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <atlimage.h>
#include <chrono>
#include <functional>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

#include "Vector2D.h"
#include "Calculator.h"

enum class WAY : int
{
	None = 0,
	Left,
	Right,
	Up,
	Down,
};

enum class KEY_INPUT : int
{
	None = 0,
	LMove = 1,
	RMove = 2,
	UMove = 3,
	DMove = 4,
	Attack = 5,
	COUNT = 6
};
