#include <iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �ﰢ���� ũ�� n(2 <= n <= 100)�� �־�����, �� �� n�ٿ��� �� 1��~n���� ���ڷ� �ﰢ�� �� �����ٿ� �ִ� ���ڰ� ���ʺ��� �־����ϴ�. �� ���ڴ� 1 �̻� 100000 ������ �ڿ����Դϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� �ִ� ����� ���� ����մϴ�.
����� ���� 2^30 ���϶�� �����ص� �����ϴ�.
*/

int Map[100][100] = { 0, };
int Cache[100][100];
int PathCache[100][100];
int N; /* 2 <= n <= 100 */

void Init();
int Solve(int X, int Y); /* ���� ū���� ã���鼭 Cache[X][Y] �� ����  */
int PathCount(int X, int Y);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Init();
		Solve(0, 0);
		cout << PathCount(0, 0) << endl;
	}
	return 0;
}

void Init()
{
	memset(Cache, 0, sizeof(Cache));
	memset(PathCache, 0, sizeof(Cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> Map[i][j];
}

int Solve(int X, int Y)
{
	int& CurSum = Cache[X][Y];

	if (X == N - 1) {
		/* base case �� ���� ���� */
		if (CurSum == 0)
			CurSum = Map[X][Y];
	}
	else {
		/* ������ ���� ���� */
		int& LSum = Cache[X + 1][Y];
		int& RSum = Cache[X + 1][Y + 1];

		if (LSum == 0)
			Solve(X + 1, Y);
		if (RSum == 0)
			Solve(X + 1, Y + 1);

		if (LSum > RSum)
			CurSum = Map[X][Y] + LSum;
		else
			CurSum = Map[X][Y] + RSum;
	}

	return CurSum;
}

int PathCount(int X, int Y)
{
	int& Count = PathCache[X][Y];

	/* �� ������ �� */
	if (X == N - 1) 
		Count = 1;

	/* �� ������ ���� �ƴѵ� �湮���� �ʾҾ� */
	if (Count == 0) {
		if (Cache[X + 1][Y] > Cache[X + 1][Y + 1])
			Count = PathCount(X + 1, Y);
		else if (Cache[X + 1][Y] < Cache[X + 1][Y + 1])
			Count = PathCount(X + 1, Y + 1);
		else
			Count = PathCount(X + 1, Y) + PathCount(X + 1, Y + 1);
	}

	return Count;
}