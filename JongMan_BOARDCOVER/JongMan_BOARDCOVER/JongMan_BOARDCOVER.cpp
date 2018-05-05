#include <iostream>
#define InRangeX(x) x < H ? x >= 0 ? true :false :false
#define InRangeY(y) y < W ? y >= 0 ? true :false :false
using namespace std;

char Map[20][20] = { 0, };
int H, W; // H, W (1 <= H,W <= 20) 
int Result;
int DotCount;

void Solve(int CurX, int CurY, int Count);
void FindTarget(int& X, int& Y);

/*
�Է�
���� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 30) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� 2���� ���� H, W (1 <= H,W <= 20) �� �־����ϴ�. ���� H �ٿ� �� W ���ڷ� �������� ����� �־����ϴ�. # �� ���� ĭ, . �� �� ĭ�� ��Ÿ���ϴ�. �Է¿� �־����� �����ǿ� �ִ� �� ĭ�� ���� 50 �� ���� �ʽ��ϴ�.

���
�� �ٿ� �ϳ��� �� ĭ�� ��� ���� ����� ���� ����մϴ�.
*/


int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Result = DotCount = 0;
		cin >> H;
		cin >> W;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> Map[j][k];
				if (Map[j][k] == '.')
					DotCount++;
			}
		}
		if (DotCount == 0)
			Result = 1;
		else if (DotCount % 3 == 0)
			Solve(0, 0, 0);

		cout << Result << endl;
	}

	return 0;
}

void Solve(int CurX, int CurY, int Count)
{
	if (Count * 3 == DotCount) {
		Result++;
		return;
	}
	int X, Y;
	X = CurX;
	Y = CurY;
	FindTarget(X, Y);

	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X + 1][Y] == '.' && Map[X + 1][Y + 1] == '.')) {
		Map[X][Y] = Map[X + 1][Y] = Map[X + 1][Y + 1] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X + 1][Y] = Map[X + 1][Y + 1] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X][Y + 1] == '.' && Map[X + 1][Y + 1] == '.'))
	{
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y + 1] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y + 1] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X][Y + 1] == '.' && Map[X + 1][Y] == '.'))
	{
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y - 1 >= 0 && Y - 1 < W) && (Map[X + 1][Y - 1] == '.' && Map[X + 1][Y] == '.'))
	{
		Map[X][Y] = Map[X + 1][Y - 1] = Map[X + 1][Y] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X + 1][Y - 1] = Map[X + 1][Y] = '.';
	}
}

void FindTarget(int& X, int& Y)
{
	for (X; X < H; X++) {
		for (Y; Y < W; Y++) {
			if (Map[X][Y] == '.')
				return;
		}
		Y = 0;
	}
}