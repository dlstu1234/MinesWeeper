#pragma once

using namespace std;

#define EMPTY 0			// �� ���� 
#define MINE 90			// ���� 
#define OPEN 30			// ���! 
#define CHECK 80		// ���� ǥ�� 
#define USER 100		// ���� 
#define LEFTCLICK 97	// ���� Ű a 
#define RIGHTCLICK 115	// ������ Ű s 
// Ű �Է� 
#define LEFT 235		// ���� ����Ű 
#define RIGHT 237		// ���� ����Ű 
#define UP 232			// ���� ����Ű 
#define DOWN 240		// �Ʒ��� ����Ű 
#define GAMEOVER 1000	// ���� ���� 
#define WIN 1001		// �¸� 

#define SAFE_DELETE(x)		{ if ((x) != nullptr) {delete(x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if ((x) != nullptr) {delete[](x); (x) = nullptr; } }


