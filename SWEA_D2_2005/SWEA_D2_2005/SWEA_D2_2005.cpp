#include <iostream>

using namespace std;

/*
[���� ����]

�Ľ�Į�� �ﰢ���� ũ�� N�� 1 �̻� 10 ������ �����̴�. (1 �� N �� 10)


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽����� N�� �־�����.


[���]

�� ���� '#t'�� �����ϰ�, ���� �ٺ��� �Ľ�Į�� �ﰢ���� ����Ѵ�.

�ﰢ�� �� ���� ó�� ���ڰ� ������ �������� �� ĭ�� �����ϰ� ���ڵ� ���̿��� �� ĭ�� ��ĭ�� ����Ѵ�.
*/

int Map[10][10] = { 1, };

void Init();
void print(int N);

int main()
{
	int TC, Input;
	cin >> TC;
	Init();
	for (int i = 1; i <= TC; i++)
	{
		cin >> Input;
		printf("#%d\n", i);
		print(Input);
	}
	return 0;
}

void Init()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j-1 >= 0)
				Map[i][j] += Map[i - 1][j-1];
			if (j < i)
				Map[i][j] += Map[i - 1][j];
		}

	}
}

void print(int N)
{
	for (int i = 0; i < N; i++) {
		printf("%d", Map[i][0]);
		for (int j = 1; j <= i; j++) {
			printf(" %d", Map[i][j]);
		}
		printf("\n");
	}
}