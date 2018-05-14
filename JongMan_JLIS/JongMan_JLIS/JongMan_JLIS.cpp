#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� c ( 1 <= c <= 50 ) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100). ���� �ٿ��� n ���� ������ A �� ���ҵ���, �� ���� �ٿ��� m ���� ������ B �� ���ҵ��� �־����ϴ�. ��� ���ҵ��� 32��Ʈ ��ȣ �ִ� ������ ������ �� �ֽ��ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ�, JLIS �� ���̸� ����մϴ�.
*/

int N, M; // A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100)
int Cache[101][101];
int ABArr[2][100] = { 0, };

int Solve(int AX, int BX);
long long Max(long long X, long long Y) { if (X > Y) return X; else return Y; }\

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M;

		for (int j = 0; j < N; j++)
			cin >> ABArr[0][j];
		for (int j = 0; j < M; j++)
			cin >> ABArr[1][j];
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				Cache[j][k] = -1; // -1 �� �ʱ�ȭ �ϴ� ������ ABArr[AX][BX]�� �Է��϶� AX+@ , BX+@ �� �ݺ����� �˻����� ���, ū���� �ȳ��ö���(�ִ밪�� ã������)


		cout << Solve(-1, -1) << endl; // -1, -1�� �� �ϴ� ������ �ݺ������� AX,BX ���� ���� �������� �����ϴµ� 0,0�� �������� �ؾ� �ϱ⶧��.
	}
	return 0;
}

int Solve(int AX, int BX)
{
	int& Res = Cache[AX + 1][BX + 1]; // -1,-1�϶��� ��� �ؼ� �� +1 ������

	if (Res != -1) // -1�� �ƴϴ�? �� ������ ����߾���.
		return Res;

	long long CurMax;
	long long a, b;
	if (AX == -1)// -1 �̱� ������ �迭�� ������ ����. �׷��� �� ���� ���� ������ ����
		a = 0 - 4987654321;
	else
		a = ABArr[0][AX];
	if (BX == -1)// -1 �̱� ������ �迭�� ������ ����. �׷��� �� ���� ���� ������ ����
		b = 0 - 4987654321;
	else
		b = ABArr[1][BX];

	CurMax = Max(a, b); // a�� b �߿� ū���� �������� �� ������ ���Ҳ���. ex) -4987654321 ���� ū ���� ������ Res = Max(Res, Solve() + 1)�� ���� �ּ� 1�� �����. 
	Res = 0;
	for (int i = AX + 1; i < N; i++) {
		if (CurMax < ABArr[0][i]) {
			Res = Max(Res, Solve(i, BX) + 1);
		}
	}

	for (int i = BX + 1; i < M; i++) {
		if (CurMax < ABArr[1][i]) {
			Res = Max(Res, Solve(AX, i) + 1);
		}
	}

	return Res;
}