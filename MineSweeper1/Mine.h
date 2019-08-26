#pragma once
#include "Map.h"
class Mine {
public:
	Mine(int width, int height);	// 초기화
	~Mine();						// 소멸자 
	int MakeMine();					// 지뢰 만들기
	void ShowMap(int loc);			// 위치값을 받아와 화면에 뿌려줌..

	void MakeCal();					// 주위 픽셀 검사 
	void Recusion(int x, int y);	// 재귀 순환 빈 배열일시 재귀로 맵을 엶
	void ShowForGameOverMineMap();	// 죽었을시 보여주는 마인 맵

	void SetIncrementFlag();		// 깃발의 갯수를 증가시킴
	void SetDecreaseFlag();			// 깃발의 갯수를 감소시킴
	void SetIncrementMineCount();	// 지뢰가 체크가 해제됫을시 다시 지뢰를 증가시키기 위함
	void SetDecreaseMineCount();	// 깃발을 체크하는데 지뢰가 맞으면 감소

	int GetCurrentFlagCount();				// 깃발 꽂인 갯수를 가지고 온다
	int GetWidth();							// 넓이의 값을 가지고 옴
	int GetHeight();						// 높이의 값을 가지고 옴
	int GetDefaultMineCount();				// 지뢰의 초기 값 갯수를 가지고 온다 
	int GetCurrentMineCount();				// 현재 지뢰의 갯수를 가지고온다
	int GetTargetMap(int loc);				// 기본 맵 위치를 가지고 온다
	int GetCalculatedMap(int loc);			// 계산된 맵위치 을 가지고 온다
	void SetTargetMap(int loc, int target); // 기본 맵에 어느 위치에 어떠한 값을 넣는다 지뢰 빈맵 깃발 등

private:
	int MineNumber; // 마인의 갯수를 담을 변수
	int FLAG;		// 깃발을 꼽을수있는 변수
	int MineCount;	// 지뢰가 몇개 생겼나??
	Map map;
};

