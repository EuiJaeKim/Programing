#include <iostream>

using namespace std;

bool Map[10][10] = { false, };
bool IsComplete[10] = { false, };
int N; // �л��� �� n (2 <= n <= 10) �л����� ���� ¦��
int M; // ģ�� ���� �� m (0 <= m <= n*(n-1)/2)
int Result;
/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 50) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �л��� �� n (2 <= n <= 10) �� ģ�� ���� �� m (0 <= m <= n*(n-1)/2) �� �־����ϴ�. �� ���� �ٿ� m ���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־����ϴ�. ��ȣ�� ��� 0 ���� n-1 ������ �����̰�, ���� ���� �Է¿� �� �� �־����� �ʽ��ϴ�. �л����� ���� ¦���Դϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ��� �л��� ģ�������� ¦������ �� �ִ� ����� ���� ����մϴ�.
*/

void Solve(int Cur, int Count)
{
	// ¦�� �� ��������� Count ���� 1����
	if (Count == N / 2) {
		Result++;
		return;
	}

	// ¦�� �� ����� ���� �ʾҴٸ� ¦�� �����
	int i = Cur;
	while (IsComplete[i] && i < N)
		i++;

	for (int j = 0; j < N; j++) {

		if (Map[i][j] && !IsComplete[j]) {
			Map[i][j] = Map[j][i] = false;
			IsComplete[i] = IsComplete[j] = true;
			Solve(Cur + 1, Count + 1);
			Map[i][j] = Map[j][i] = true;
			IsComplete[i] = IsComplete[j] = false;
		}

	}
}
void MapInit()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Map[i][j] = false;
}

int main()
{
	int TC;


	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int A, B;
		cin >> N;
		cin >> M;
		Result = 0;
		for (int j = 0; j < M; j++) {
			cin >> A;
			cin >> B;
			Map[A][B] = Map[B][A] = true;
		}
		Solve(0, 0);
		MapInit();

		cout << Result << endl;
	}

	return 0;
}