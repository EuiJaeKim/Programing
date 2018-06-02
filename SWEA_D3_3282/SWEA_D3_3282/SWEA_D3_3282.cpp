#include <iostream>
#include <string.h>

using namespace std;

/*
[�Է�]

ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.

�� �׽�Ʈ ���̽��� ù° �ٿ� ������ ������ ������ ������ N K�� �־�����.

���� N���� �ٿ� ���ļ� i�� ������ ������ ��Ÿ���� ����  Vi�� ��ġ Ci�� �־�����.

[���]

�� �׽�Ʈ ���̽����� ���濡 ���� �� �ִ� �ִ� ��ġ�� ����Ѵ�.
*/
#define MAX(A,B) A>B ? A : B
int N; /* ������ ���� (1��N��100) */
int K; /* ������ ���� (1��K��1000) */
int Max;
int Map[100][2]; /* 0 : ���� 1: ��ġ */

void Search(int Count, int Cur, int SumC, int SumV);

int main()
{
	int TC, Temp;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		memset(Map, 0, sizeof(Map));
		Max = 0;
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> Map[j][0] >> Map[j][1];
		for (int i = 1; i <= N; i++) {
			Temp = Max;
			Search(i, 0, 0, 0);
			if (Temp == Max)
				break;
			else
				Temp = Max;
		}
		printf("#%d %d\n", i, Max);
	}

	return 0;
}

void Search(int Count, int Cur, int SumC, int SumV)
{
	if (Count == 0)
		Max = MAX(SumC, Max);
	else if (SumV + Map[Cur][0] == K) {
		Max = MAX(SumC, Max);
	}
	else if (SumV + Map[Cur][0] < K) {
		for (int i = Cur; i < N - 1; i++) {
			if (SumV + Map[i][0] <= K)
				Search(Count - 1, i + 1, SumC + Map[i][1], SumV + Map[i][0]);
		}
	}
	return;
}