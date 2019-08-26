#include "pch.h"
#include "Game.h"

void Game::GameStart()
{
	cout << "사이즈를 입력 하십시오" << endl;
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
			cout << "s : 체크 a : 선택" << endl;
			cout << "체크 포인트 갯수 : " << mt.GetCurrentFlagCount() << " 개 남은 마인의 갯수 : " << mt.GetCurrentMineCount() << endl;
		}
		else if (action == GAMEOVER)
		{
			system("cls");
			cout << "게임 끝!" << endl;
			mt.ShowForGameOverMineMap();
			Sleep(1000);
			system("pause");
			exit(1);
		}
		else if (action == WIN)
		{
			system("cls");
			cout << "이겼습니다!" << endl;
			Sleep(1000);
			system("pause");
			exit(1);
		}
	}
}

int Game::Move(Mine& p, int *x, int *y)  //MOVE 함수 
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
	{   // CHECK는 깃발을 의미 합니다 
		if (p.GetCalculatedMap((*x) + (*y)) == 0 && p.GetTargetMap((*x) + (*y)) != CHECK)  // 깃발이 안꼽혀 있을때에만 할수 있음 
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
	else if (num == RIGHTCLICK) // ENTER  // 체크 깃발
	{
		if (p.GetTargetMap((*x) + (*y)) == EMPTY && p.GetCurrentFlagCount() < p.GetDefaultMineCount()) //빈 공간이고 플래그 갯수를 가져오는데 지뢰의 갯수보다 적다면 여기 블락 실행
		{
			p.SetIncrementFlag(); //플래그의 갯수를 증가시킴.
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
