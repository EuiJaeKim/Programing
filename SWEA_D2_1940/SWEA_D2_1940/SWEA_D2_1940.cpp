#include <iostream>

using namespace std;

/*

[�������]

1. N�� 2�̻� 30������ �����̴�. (2 �� N �� 30)

2. ���ӵ��� ���� 1 m/s2 Ȥ�� 2 m/s2 �̴�.

3. ���� �ӵ����� ������ �ӵ��� �� Ŭ ���, �ӵ��� 0 m/s �� �ȴ�.


[�Է�]

�Է��� ù �ٿ� �� �׽�Ʈ ���̽��� ���� T, ���� �ٺ��� �� �׽�Ʈ ���̽��� �־�����.

�׽�Ʈ ���̽� ù �ٿ��� Command �� �� N�� �־�����, ��° �ٺ���, �� �ٸ��� ������ Command�� �־�����.


[���]

�׽�Ʈ ���̽� t�� ���� ����� ��#t���� ���, �� ĭ ���, ������ ����Ѵ�.

(t�� �׽�Ʈ ���̽��� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�.)

*/

int main()
{
	int TC;
	int N; // �Է����� �־��� N ���� command
	int Speed, Result, Order, Value;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Speed = Result = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> Order;
			if (Order == 0) {
				Result += Speed;
				continue;
			}
			cin >> Value;
			if (Order == 1)
				Speed += Value;
			else
				Speed -= Value;
			if (Speed < 0)
				Speed = 0;
			Result += Speed;
		}
		printf("#%d %d\n",i,Result);
	}

	return 0;
}