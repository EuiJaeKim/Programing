#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 50) �� �־����ϴ�. �� �� �� �ٿ� �簢���� �ʺ� n (1 <= n <= 100) �� �־����ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ���Ī Ÿ�ϸ� ����� ���� 1,000,000,007 �� ���� �������� ����մϴ�.
*/
long long Map[101] = { 0, };
int N; /* �簢���� �ʺ� n (1 <= n <= 100) */

void Init();
int Solve(int n);

int main()
{
	int TC;

	cin >> TC;
	Init();

	for (int i = 0; i < TC; i++) {
		cin >> N;
		cout << Solve(N) << endl;
	}
	return 0;
}

int Solve(int n)
{
	long long Temp = (Map[n] - Map[n / 2] + 1000000007) % 1000000007;

	if (n % 2 == 1)// Ȧ����
		return Temp;

	Temp = (Temp - Map[(n / 2) - 1] + 1000000007);
	Temp %= 1000000007;

	return Temp;
}

void Init()
{
	Map[0] = 1;
	Map[1] = 1;
	for (int i = 2; i < 101; i++)
		Map[i] = (Map[i - 1] + Map[i - 2]) % 1000000007;
}