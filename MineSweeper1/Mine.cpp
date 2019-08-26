#include "pch.h"
#include "Mine.h"

Mine::Mine(int width, int height) :FLAG(0), map(width, height)
{
}

void Mine::ShowForGameOverMineMap()
{
	for (int i = 0; i < map.GetHeight(); i++)
	{
		for (int j = 0; j < map.GetWidth(); j++)
		{
			if (map.GetCalculatedMap(i * map.GetHeight() + j) == MINE)
			{
				cout << "��";
			}
			else
				cout << "��";
		}
		cout << endl;
	}
}
//������ ����� ��
int Mine::MakeMine()
{
	if (map.GetWidth() == 0 || map.GetHeight() == 0 || map.GetWidth() < 5 || map.GetHeight() < 5)
	{
		cout << " error ";
		exit(1);
		return 0;
	}
	int Weeper = 20;  //���� ������ ��Ÿ���°�
	int Sum = map.GetWidth() * map.GetHeight();
	int Num, count = 0;

	srand((unsigned)time(NULL));
	for (int i = 0; i < Weeper;)
	{
		Num = rand() % Sum - 1;
		if (Num)
		{
			map.SetTargetMap(Num, MINE);
			i++;
			count++;
		}
	}
	MineNumber = count;		//ī��Ʈ �ö󰣰Ÿ� MINE ������ ǥ���ϱ����� ������ ����
	MineCount = count;		//MINECOUNT ������ �Ȱ��� �ְ� �� ������ ���� ���� �ѹ��� ���ϱ� ���� �����̴� 
	return 1;
}
Mine::~Mine()
{
	map.~Map();
}
void Mine::ShowMap(int loc)
{
	map.ShowMap(loc);
}
void Mine::MakeCal()
{
	int Count = 0;
	for (int i = 0; i < map.GetHeight(); i++)  // ����
	{
		for (int j = 0; j < map.GetWidth(); j++)  // ����
		{
			if (map.GetTargetMap(i * map.GetHeight() + j) != MINE)
			{
				for (int InHeight = i - 1; InHeight <= i + 1; InHeight++)
				{
					for (int InWidth = j - 1; InWidth <= j + 1; InWidth++)
					{
						if (InHeight < 0 || InWidth < 0 || InHeight == map.GetHeight() || InWidth == map.GetWidth())
						{
							continue;
						}
						else if (map.GetTargetMap(InHeight * map.GetHeight() + InWidth) == MINE)
						{
							Count++;
						}

					}
				}
				map.SetCalculatedMap(i * map.GetHeight() + j, Count);
				cout << Count;
				Count = 0;
			}
			if (GetTargetMap(i * map.GetHeight() + j) == MINE)
			{
				map.SetCalculatedMap(i * map.GetHeight() + j, MINE);
				cout << "��";
			}
		}
		cout << endl;
	}
	map.InitTargetMap();
}
void Mine::Recusion(int x, int y)
{
	int loc = x + y;
	if (map.GetTargetMap(loc) == EMPTY)
	{
		map.SetTargetMap(loc, OPEN);
	}
	if (map.GetCalculatedMap(loc + 1) != EMPTY && loc + 1 < loc + ((y - loc) + map.GetHeight())) // ������ ��ȣ ǥ��
	{
		map.SetTargetMap(loc + 1, map.GetCalculatedMap(loc + 1));
	}
	if (map.GetCalculatedMap(loc - 1) != EMPTY && loc - 1 >= y) // ���� ��ȣ ǥ��
	{
		map.SetTargetMap(loc - 1, map.GetCalculatedMap(loc - 1));
	}
	if (map.GetCalculatedMap(loc + map.GetWidth()) != EMPTY && loc + map.GetWidth() <= ((map.GetWidth()*map.GetHeight()) - map.GetWidth()) + x) // �Ʒ� ��ȣ ǥ�� 
	{
		map.SetTargetMap(loc + map.GetWidth(), map.GetCalculatedMap(loc + map.GetWidth()));
	}
	if (map.GetCalculatedMap(loc - map.GetWidth()) != EMPTY && loc - map.GetWidth() >= x) // �� ��ȣ ǥ�� 
	{
		map.SetTargetMap(loc - map.GetWidth(), map.GetCalculatedMap(loc - map.GetWidth()));
	}
	if (map.GetCalculatedMap(loc + 1) == EMPTY && loc + 1 < loc + ((y - loc) + map.GetHeight()) && map.GetTargetMap(loc + 1) == EMPTY) Recusion(x + 1, y); // �����ʱ��
	if (map.GetCalculatedMap(loc - 1) == EMPTY && loc - 1 >= y && map.GetTargetMap(loc - 1) == EMPTY) Recusion(x - 1, y); //���� ���
	if (map.GetCalculatedMap(loc + map.GetWidth()) == EMPTY && loc + map.GetWidth() <= ((map.GetWidth()*map.GetHeight()) - map.GetWidth()) + x && map.GetTargetMap(loc + map.GetWidth()) == EMPTY) Recusion(x, y + map.GetWidth()); //�Ʒ��α�� 
	if (map.GetCalculatedMap(loc - map.GetWidth()) == EMPTY && loc - map.GetWidth() >= x && map.GetTargetMap(loc - map.GetWidth()) == EMPTY) Recusion(x, y - map.GetWidth()); // ���α�� */
}
void Mine::SetIncrementFlag()
{
	FLAG++;
}
void Mine::SetDecreaseFlag()
{
	FLAG--;
}
void Mine::SetIncrementMineCount()
{
	MineCount++;
}
void Mine::SetDecreaseMineCount()
{
	MineCount--;
}
int Mine::GetWidth()
{
	return map.GetWidth();
}
int Mine::GetHeight()
{
	return map.GetHeight();
}
int Mine::GetDefaultMineCount()
{
	return MineNumber;
}
int Mine::GetCurrentFlagCount()
{
	return FLAG;
}
int Mine::GetCurrentMineCount()
{
	return MineCount;
}
int Mine::GetTargetMap(int loc)
{
	return map.GetTargetMap(loc);
}
int Mine::GetCalculatedMap(int loc)
{
	return map.GetCalculatedMap(loc);
}
void Mine::SetTargetMap(int loc, int target)
{
	map.SetTargetMap(loc, target);
}

