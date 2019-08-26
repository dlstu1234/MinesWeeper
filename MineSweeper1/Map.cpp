#include "pch.h"
#include "Map.h"


Map::Map(int width, int height) :Width(width), Height(height)
{
	int sum = width * height;
	Target_Map = new int[sum];
	Calculated_Map = new int[sum];
	memset(Target_Map, EMPTY, sizeof(int) * sum);
	memset(Calculated_Map, EMPTY, sizeof(int) * sum);
}


Map::~Map()
{
	SAFE_DELETE_ARR(Target_Map);
	SAFE_DELETE_ARR(Calculated_Map);
}

void Map::ShowMap(int loc)
{
	system("cls");
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (Target_Map[i * Height + j] == MINE && i * Height + j != loc)
			{
				cout << "¢Â";
			}
			else if (Target_Map[i * Height + j] == EMPTY && i * Height + j != loc)
			{
				cout << "¡à";
			}
			else if (i * Height + j == loc)
			{
				cout << "¡Ú";
			}
			else if (Target_Map[i * Height + j] == OPEN)
			{
				cout << "¡á";
			}
			else if (Target_Map[i * Height + j] == CHECK)
			{
				cout << "¢Ò";
			}
			else
			{
				cout << Target_Map[i * Height + j];
			}
		}
		cout << endl;
	}
}
