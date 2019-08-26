#pragma once
class Map
{
public:
	Map(int width, int height);
	~Map();

	void ShowMap(int loc);				// 맵 보여주기
	int GetWidth() { return Width; }	// 넓이 가져옴
	int GetHeight() { return Height; }	// 높이 가져옴

	void SetTargetMap(int loc, int target)		{ Target_Map[loc] = target; }		// 비어있는 배열에 위치와 타겟값을 세팅
	void SetCalculatedMap(int loc, int target)	{ Calculated_Map[loc] = target; }	// 위치와 타겟값을 세팅 (계산을 하기 위한 배열)

	int GetTargetMap(int loc)		{ return Target_Map[loc]; }								// 배열의 위치를 가져옴
	int GetCalculatedMap(int loc)	{ return Calculated_Map[loc]; }							// 계산된 배열의 위치를 가져옴
	void InitTargetMap()			{ memset(Target_Map, 0, sizeof(int)*Width*Height); }	// 배열 초기화


private:
	const int Width;		// 넓이
	const int Height;		// 높이
	int* Target_Map;		// 빈 배열
	int* Calculated_Map;	// 계산된 배열
};

