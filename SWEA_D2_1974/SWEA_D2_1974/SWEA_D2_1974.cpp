#include <iostream>

using namespace std;

/*

[���� ����]

1. ������ ��� ���ڷ� ä���� ���·� �־�����.

2. �Է����� �־����� ������ ��� ���ڴ� 1 �̻� 9 ������ �����̴�.


[�Է�]

�Է��� ù �ٿ� �� �׽�Ʈ ���̽��� ���� T�� �´�.

���� �ٺ��� �� �׽�Ʈ ���̽��� �־�����.

�׽�Ʈ ���̽��� 9 x 9 ũ���� ������ �������̴�.


[���]

�׽�Ʈ ���̽� t�� ���� ����� ��#t���� ���, �� ĭ ���, ������ ����Ѵ�.

*/

#define Length 9

int Map[9][9] = { 0, };

int Solve();

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		/* 1. �Է´� */
		for (int j = 0; j < Length; j++)
			for (int k = 0; k < Length; k++)
				cin >> Map[j][k];
		/* 2. ����Ϸ� ����� */
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

int Solve()
{
	int Sum;

	/* 3. ������ �˻� */
	for (int i = 0; i < Length; i++) {
		Sum = 0;
		for (int j = 0; j < Length; j++)
			Sum += Map[i][j];
		if (Sum != 45)
			return 0;
	}
	/* 4. ���ο� �˻� */
	for (int i = 0; i < Length; i++) {
		Sum = 0;
		for (int j = 0; j < Length; j++)
			Sum += Map[j][i];
		if (Sum != 45)
			return 0;
	}
	/* 5. 3x3 �˻� */

	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			Sum = 0;
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					Sum += Map[x][y];
				}
			}
			if (Sum != 45)
				return 0;
		}
	}

	return 1;
}