#pragma once
class Map
{
public:
	Map(int width, int height);
	~Map();

	void ShowMap(int loc);				// �� �����ֱ�
	int GetWidth() { return Width; }	// ���� ������
	int GetHeight() { return Height; }	// ���� ������

	void SetTargetMap(int loc, int target)		{ Target_Map[loc] = target; }		// ����ִ� �迭�� ��ġ�� Ÿ�ٰ��� ����
	void SetCalculatedMap(int loc, int target)	{ Calculated_Map[loc] = target; }	// ��ġ�� Ÿ�ٰ��� ���� (����� �ϱ� ���� �迭)

	int GetTargetMap(int loc)		{ return Target_Map[loc]; }								// �迭�� ��ġ�� ������
	int GetCalculatedMap(int loc)	{ return Calculated_Map[loc]; }							// ���� �迭�� ��ġ�� ������
	void InitTargetMap()			{ memset(Target_Map, 0, sizeof(int)*Width*Height); }	// �迭 �ʱ�ȭ


private:
	const int Width;		// ����
	const int Height;		// ����
	int* Target_Map;		// �� �迭
	int* Calculated_Map;	// ���� �迭
};

