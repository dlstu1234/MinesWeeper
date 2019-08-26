#pragma once
#include "Map.h"
class Mine {
public:
	Mine(int width, int height);	// �ʱ�ȭ
	~Mine();						// �Ҹ��� 
	int MakeMine();					// ���� �����
	void ShowMap(int loc);			// ��ġ���� �޾ƿ� ȭ�鿡 �ѷ���..

	void MakeCal();					// ���� �ȼ� �˻� 
	void Recusion(int x, int y);	// ��� ��ȯ �� �迭�Ͻ� ��ͷ� ���� ��
	void ShowForGameOverMineMap();	// �׾����� �����ִ� ���� ��

	void SetIncrementFlag();		// ����� ������ ������Ŵ
	void SetDecreaseFlag();			// ����� ������ ���ҽ�Ŵ
	void SetIncrementMineCount();	// ���ڰ� üũ�� ���������� �ٽ� ���ڸ� ������Ű�� ����
	void SetDecreaseMineCount();	// ����� üũ�ϴµ� ���ڰ� ������ ����

	int GetCurrentFlagCount();				// ��� ���� ������ ������ �´�
	int GetWidth();							// ������ ���� ������ ��
	int GetHeight();						// ������ ���� ������ ��
	int GetDefaultMineCount();				// ������ �ʱ� �� ������ ������ �´� 
	int GetCurrentMineCount();				// ���� ������ ������ ������´�
	int GetTargetMap(int loc);				// �⺻ �� ��ġ�� ������ �´�
	int GetCalculatedMap(int loc);			// ���� ����ġ �� ������ �´�
	void SetTargetMap(int loc, int target); // �⺻ �ʿ� ��� ��ġ�� ��� ���� �ִ´� ���� ��� ��� ��

private:
	int MineNumber; // ������ ������ ���� ����
	int FLAG;		// ����� �������ִ� ����
	int MineCount;	// ���ڰ� � ���峪??
	Map map;
};

