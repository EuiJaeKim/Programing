#include <iostream>

using namespace std;

/*

[���� ����]

N�� 3 �̻� 7 �����̴�.

[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ� N�� �־�����,

���� N �ٿ��� N x N ����� �־�����.

[���]

����� ù ���� '#t'�� �����ϰ�,

���� N�ٿ� ���ļ� 90��, 180��, 270�� ȸ���� ����� ����Ѵ�.

�Է°��� �޸� ��¿����� ȸ���� ��� ���̿��� ������ �����Կ� �����϶�.

*/

int N;
char Map[7][7];

void Solve();

int main()
{
	int TC, Input;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				cin >> Input;
				Map[j][k] = Input + '0';
			}
		printf("#%d\n", i);
		Solve();
	}

	return 0;
}

void Solve()
{
	for (int i = 0; i < N; i++) {

		for (int k = N - 1; k >= 0; k--) {
			cout << Map[k][i];
		}
		cout << " ";
		for (int k = N - 1; k >= 0; k--) {
			cout << Map[N - i - 1][k];
		}
		cout << " ";
		for (int k = 0; k < N; k++) {
			cout << Map[k][N - i - 1];
		}
		cout << endl;
	}
}