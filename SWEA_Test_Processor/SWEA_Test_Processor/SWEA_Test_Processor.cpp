#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/*
[�Է�]

�Է��� ���� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־����� �� ���� �ٺ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù �ٿ��� N���� �־�����, ���� N�ٿ� ���ļ� �߽ó뽺�� �ʱ� ���°� N x N �迭�� �־�����.

0�� �� cell�� �ǹ��ϸ�, 1�� core�� �ǹ��ϰ�, �� ���� ���ڴ� �־����� �ʴ´�.



[���]

�� �׽�Ʈ ���̽����� '#X'�� ���, �� ĭ ���, ������ ����Ѵ�.
*/
#define MIN(A,B) A>B ? B : A
int N;
int Map[12][12]; /* �� */
int CoreCount; /* �ھ��� ���� */
int CoreMap[12][2]; /* �ھ��� ��ġ */
int CoreVal[12][4]; /* 1 x-@ �� 2 y-@ �� 3 x+@ �� 4 y+@ �� */
int CoreCur[12]; /* Core�� ����Ǿ� �ִ� ���� */
int Length;
int Res;
int Result;

void Init();
void Solve(int Core, int Count, int LengthSum); /* n��° Core, ����� �ھ� �Ѱ��� Count, ����� �ھ��� �������� Length */
bool IsConnect(int CoreNum, int Loc);
void DisConnect(int CoreNum, int Loc);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N;
		Init();
		Solve(0, Res, 0);
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Init()
{
	memset(Map, 0, sizeof(Map));
	memset(CoreMap, 0, sizeof(CoreMap));
	memset(CoreVal, 0, sizeof(CoreVal));
	memset(CoreCur, 0, sizeof(CoreCur));
	Res = 0;
	CoreCount = 0;
	Result = 987654321;
	int Input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Input;
			if (Input == 1) {
				Map[i][j] = 1;
				if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
					Res++;
				else {
					CoreMap[CoreCount][0] = i;
					CoreMap[CoreCount++][1] = j;
				}
			}
		}
	}
	int Dis[4], A, B, C, D;
	for (int i = 0; i < CoreCount; i++) {
		A = Dis[0] = CoreMap[i][0];
		B = Dis[1] = CoreMap[i][1];
		C = Dis[2] = N - 1 - CoreMap[i][0];
		D = Dis[3] = N - 1 - CoreMap[i][1];
		sort(Dis, Dis + 4);
		for (int j = 0; j < 4; j++) {
			if (A != -1 && Dis[j] == A) {
				CoreVal[i][j] = 1;
				A = -1;
			}
			else if (B != -1 && Dis[j] == B) {
				CoreVal[i][j] = 2;
				B = -1;
			}
			else if (C != -1 && Dis[j] == C) {
				CoreVal[i][j] = 3;
				C = -1;
			}
			else if (D != -1 && Dis[j] == D) {
				CoreVal[i][j] = 4;
				D = -1;
			}
		}
	}
}

void Solve(int Core, int Count, int LengthSum)
{

	if (Core == CoreCount) {
		if (Count == Res)
			Result = MIN(Result, LengthSum);
		else if (Count > Res) {
			Result = LengthSum;
			Res = Count;
		}
		return;
	}
	// �� �ھ �����ϸ鼭 ��������. �Ǹ����� �ھ� �����ϰ� Res ��. ũ�ų� ���ٸ� ���ἱ �� ����.

	for (int i = 0; i < 4; i++) {
		if (IsConnect(Core, i)) {
			Solve(Core + 1, Count + 1, LengthSum + Length - 1);
			DisConnect(Core, i);
		}
	}
	Solve(Core + 1, Count, LengthSum);

	return;
}

bool IsConnect(int CoreNum, int Loc)
{
	int i = 1;

	if (CoreVal[CoreNum][Loc] == 1) {
		while (CoreMap[CoreNum][0] - i >= 0 && Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] == 0)
			i++;
		if (CoreMap[CoreNum][0] - i == -1) {
			i = 1;
			while (CoreMap[CoreNum][0] - i >= 0) {
				Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 2) {
		while (CoreMap[CoreNum][1] - i >= 0 && Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] == 0)
			i++;
		if (CoreMap[CoreNum][1] - i == -1) {
			i = 1;
			while (CoreMap[CoreNum][1] - i >= 0) {
				Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 3) {
		while (CoreMap[CoreNum][0] + i < N && Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] == 0)
			i++;
		if (CoreMap[CoreNum][0] + i == N) {
			i = 1;
			while (CoreMap[CoreNum][0] + i < N) {
				Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 4) {
		while (CoreMap[CoreNum][1] + i < N && Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] == 0)
			i++;
		if (CoreMap[CoreNum][1] + i == N) {
			i = 1;
			while (CoreMap[CoreNum][1] + i < N) {
				Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	return false;
}

void DisConnect(int CoreNum, int Loc)
{
	int i = 1;

	if (CoreVal[CoreNum][Loc] == 1) {
		while (CoreMap[CoreNum][0] - i >= 0) {
			Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 2) {
		while (CoreMap[CoreNum][1] - i >= 0) {
			Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 3) {
		while (CoreMap[CoreNum][0] + i < N) {
			Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 4) {
		while (CoreMap[CoreNum][1] + i < N) {
			Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] = 0;
			i++;
		}
	}
}