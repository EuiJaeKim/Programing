#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (<= 50) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���Ե� ������ �� N (<= 500) �� �־�����. �� ���� �ٿ� ������ N���� ������ �־�����. �� ������ 1 �̻� 100,000 ������ �ڿ����̴�.

���
�� �׽�Ʈ���̽����� �� �پ�, �־��� ������ ���� �� ���� �κ� ������ ���̸� ����Ѵ�.
*/
int Map[500] = { 0, };
int Cache[500] = { 0, };
int N;// ������ ���Ե� ������ �� N (<= 500)
int Max;
void Solve(int X);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N;
		Max = 0;
		for (int j = 0; j < N; j++) {
			cin >> Map[j];
			Cache[j] = 0;
		}
		Solve(N - 1);
		cout << Max << endl;
	}
	return 0;
}

void Solve(int X)
{
	if (X < 0)
		return;

	Cache[X] = 1;

	for (int i = 0; X + i < N; i++) {
		if (Map[X + i] > Map[X]) { // 1. ������
			if (Cache[X + i] == 0) // 1-1. ù�湮
				Solve(X + i);
			// 1-2. ��湮
			if (Cache[X] <= Cache[X + i] + 1)
				Cache[X] = Cache[X + i] + 1;

			if (Max < Cache[X]) {
				Max = Cache[X];
				break;
			}
		}
	}
	Solve(X - 1);
}