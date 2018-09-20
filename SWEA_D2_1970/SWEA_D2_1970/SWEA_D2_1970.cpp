#include <iostream>

using namespace std;

/*

[���� ����]

1. N�� 10�̻� 1,000,000������ �����̴�. (10 �� N �� 1,000,000)

2. N�� ������ �ڸ����� �׻� 0�̴�. (ex : 32850)


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽����� N�� �־�����.


[���]

�� ���� '#t'�� �����ϰ�, �����ٿ� �� ���� �������� �ʿ��� ������ ��ĭ�� ���̿� �ΰ� ����Ѵ�.

*/

void Solve(int Input);

int main()
{
	int TC, N;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		printf("#%d\n", i);
		Solve(N);
	}

	return 0;
}

void Solve(int Input)
{
	int Count, Cost = 50000;

	for (int i = 1; i < 8; i++) {
		Count = 0;
		if (Input >= Cost) {
			Count = Input / Cost;
			Input -= Count * Cost;
		}
		cout << Count << " ";
		if (i % 2 == 1)
			Cost /= 5;
		else
			Cost /= 2;
	}
	cout << Input / 10 << endl;
}