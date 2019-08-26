#pragma once

using namespace std;

#define EMPTY 0			// 빈 공간 
#define MINE 90			// 지뢰 
#define OPEN 30			// 까라! 
#define CHECK 80		// 지뢰 표시 
#define USER 100		// 유저 
#define LEFTCLICK 97	// 왼쪽 키 a 
#define RIGHTCLICK 115	// 오른쪽 키 s 
// 키 입력 
#define LEFT 235		// 좌측 방향키 
#define RIGHT 237		// 우측 방향키 
#define UP 232			// 위쪽 방향키 
#define DOWN 240		// 아래쪽 방향키 
#define GAMEOVER 1000	// 게임 오버 
#define WIN 1001		// 승리 

#define SAFE_DELETE(x)		{ if ((x) != nullptr) {delete(x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if ((x) != nullptr) {delete[](x); (x) = nullptr; } }


