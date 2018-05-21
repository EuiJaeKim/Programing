#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ��(C <= 50)�� �־����ϴ�. ���� C�ٿ� ���� 1���� �ڿ����� n(1 <= n <= 100)�� �־����ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ����� ���� 1000000007�� ���� �������� ����մϴ�.
*/

long long Map[101];
void Init();

int main()
{
	int TC;
	int Num;
	cin >> TC;
	Init();
	for (int i = 0; i < TC; i++) {
		cin >> Num;
		cout << Map[Num]  << endl;
	}

	return 0;
}

void Init()
{
	Map[1] = 1;
	Map[2] = 2;
	for (int i = 3; i <= 100; i++)
		Map[i] = (Map[i - 1] + Map[i - 2]) % 1000000007;
}