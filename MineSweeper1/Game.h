#pragma once

#include "Mine.h"
// ���� ���� �Լ�
class Game
{
public:
	void GameStart(); // ����
	int Move(Mine& p, int *x, int *y); // ������
	int GetUserInput(); // Ű�Է�

private:
	int Width = 10;
	int Height = 10;

	int x = 0, y = 0;
	int action = 0;
};

