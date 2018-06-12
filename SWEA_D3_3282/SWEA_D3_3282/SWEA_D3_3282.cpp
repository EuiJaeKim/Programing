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
int Map[100][2]; /* 0 : ���� 1: ��ġ */
int Cache[100][1001];

int Search(int Count, int Vol);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		memset(Map, 0, sizeof(Map));
		memset(Cache, -1, sizeof(Cache));
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> Map[j][0] >> Map[j][1];

		printf("#%d %d\n", i, Search(0,K));
	}

	return 0;
}

int Search(int Count, int Vol)
{
	/* Base Case */
	if (Count == N)
		return 0;

	if (Cache[Count][Vol] != -1)
		return Cache[Count][Vol];

	Cache[Count][Vol] = Search(Count + 1, Vol);

	if (Vol >= Map[Count][0])
		Cache[Count][Vol] = MAX(Cache[Count][Vol], Search(Count + 1, Vol - Map[Count][0]) + Map[Count][1]);

	return Cache[Count][Vol];
}