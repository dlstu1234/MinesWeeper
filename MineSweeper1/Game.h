#pragma once

#include "Mine.h"
// 게임 내부 함수
class Game
{
public:
	void GameStart(); // 시작
	int Move(Mine& p, int *x, int *y); // 움직임
	int GetUserInput(); // 키입력

private:
	int Width = 10;
	int Height = 10;

	int x = 0, y = 0;
	int action = 0;
};

