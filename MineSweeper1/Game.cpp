#include "pch.h"
#include "Game.h"

void Game::GameStart()
{
	cout << "����� �Է� �Ͻʽÿ�" << endl;
	cin >> Width, Height;

	Mine mt(Width, Height);
	mt.MakeMine();
	mt.MakeCal();
	while (action != GAMEOVER && action != WIN)
	{
		action = Move(mt, &x, &y);
		if (action != WIN && action != GAMEOVER)
		{
			mt.ShowMap(action);
			cout << "s : üũ a : ����" << endl;
			cout << "üũ ����Ʈ ���� : " << mt.GetCurrentFlagCount() << " �� ���� ������ ���� : " << mt.GetCurrentMineCount() << endl;
		}
		else if (action == GAMEOVER)
		{
			system("cls");
			cout << "���� ��!" << endl;
			mt.ShowForGameOverMineMap();
			Sleep(1000);
			system("pause");
			exit(1);
		}
		else if (action == WIN)
		{
			system("cls");
			cout << "�̰���ϴ�!" << endl;
			Sleep(1000);
			system("pause");
			exit(1);
		}
	}
}

int Game::Move(Mine& p, int *x, int *y)  //MOVE �Լ� 
{
	int num;
	int loc = 0;
	int CheckWin = 0;
	num = GetUserInput();
	if (num == RIGHT && (*x) < p.GetWidth() - 1) (*x)++;
	else if (num == LEFT && (*x) > 0) (*x)--;
	else if (num == UP && (*y) - p.GetWidth() >= 0) (*y) -= p.GetWidth();
	else if (num == DOWN && (*y) + p.GetWidth() < p.GetHeight()*p.GetWidth()) (*y) += p.GetWidth();
	else if (num == LEFTCLICK)
	{   // CHECK�� ����� �ǹ� �մϴ� 
		if (p.GetCalculatedMap((*x) + (*y)) == 0 && p.GetTargetMap((*x) + (*y)) != CHECK)  // ����� �Ȳ��� ���������� �Ҽ� ���� 
		{
			p.Recusion(*x, *y);
		}
		else if (p.GetCalculatedMap((*x) + (*y)) == MINE)
		{
			CheckWin = GAMEOVER;
		}
		else if (p.GetTargetMap((*x) + (*y)) != CHECK)
		{
			p.SetTargetMap((*x) + (*y), p.GetCalculatedMap((*x) + (*y)));
		}
	}
	else if (num == RIGHTCLICK) // ENTER  // üũ ���
	{
		if (p.GetTargetMap((*x) + (*y)) == EMPTY && p.GetCurrentFlagCount() < p.GetDefaultMineCount()) //�� �����̰� �÷��� ������ �������µ� ������ �������� ���ٸ� ���� ��� ����
		{
			p.SetIncrementFlag(); //�÷����� ������ ������Ŵ.
			p.SetTargetMap((*x) + (*y), CHECK);
			if (p.GetCalculatedMap((*x) + (*y)) == MINE)
			{
				p.SetDecreaseMineCount();
				if (p.GetCurrentMineCount() == 0)
				{
					CheckWin = WIN;
				}
			}
		}
		else if (p.GetTargetMap((*x) + (*y)) == CHECK)
		{
			p.SetDecreaseFlag();
			p.SetTargetMap((*x) + (*y), EMPTY);
			if (p.GetCalculatedMap((*x) + (*y)) == MINE) p.SetIncrementMineCount();
		}
	}
	if (CheckWin != GAMEOVER && CheckWin != WIN)
	{
		loc = (*x) + (*y);
	}
	else
	{
		loc = CheckWin;
	}
	return loc;
}

int Game::GetUserInput()
{
	int input = 0;
	do {
		input |= _getch();
	} while (input == 224);
	return input;
}
