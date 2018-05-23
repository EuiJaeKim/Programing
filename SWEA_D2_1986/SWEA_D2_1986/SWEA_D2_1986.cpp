#include <iostream>

using namespace std;

/*
[�������]

N�� 1 �̻� 10 ������ �����̴�. (1 �� N �� 10)


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽����� N�� �־�����.


[���]

�� ���� '#t'�� �����ϰ�, ������ �� ĭ �� ���� ������ ���� ����Ѵ�.
*/
int Map[11] = { 0, };

void Init();

int main()
{
	int TC;
	cin >> TC;
	Init();
	for (int i = 1; i <= TC; i++) {
		printf("#%d %d\n", i, Map[i]);
	}

	return 0;
}

void Init()
{
	for (int i = 1; i < 11; i++) {
		if (i % 2 == 0)
			Map[i] = Map[i - 1] - i;
		else
			Map[i] = Map[i - 1] + i;
	}

}