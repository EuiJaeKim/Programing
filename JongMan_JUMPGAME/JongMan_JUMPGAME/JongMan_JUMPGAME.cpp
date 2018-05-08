#include <iostream>

using namespace std;
/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ũ�� n(2 <= n <= 100)�� �־�����, �� �� n�ٿ� �� n���� ���ڷ� ���� ������ �� ĭ�� ���� ���ڵ��� �־����ϴ�. ������ �Ʒ� �ִ� �� �� ��ġ���� 0�� �־����ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٷ�, ���������� �� ������ ������ �� ���� ��� "YES"��, �ƴ� ��� "NO"�� ����մϴ�. (����ǥ ����)
*/
int N;
int Map[100][100] = { -1, }; // 0 : ������, 1~9 ������.
bool Visit[100][100] = { false, };

bool InRange(int A) { if (A >= N) return false; else return true; }
bool Solve(int StartX, int StartY);

int main()
{
	int TC;
	cin >> TC;
	//memset(Map, -1, sizeof(Map));
	for (int i = 0; i < TC; i++) {
		//memset(Visit, false, sizeof(Visit));
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> Map[j][k];
				Visit[j][k] = false;
			}
				
		}


		if (Solve(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

bool Solve(int StartX, int StartY)
{
	int& Cur = Map[StartX][StartY];
	/* Base Case */
	if (Cur == 0)
		return true;
	bool Ret = false;

	Visit[StartX][StartY] = true;
	/* ���� �ȿ� ������ �̹� ���� ���� �ƴѰ�� */
	if (InRange(StartX + Cur) && !Visit[StartX + Cur][StartY])
		Ret = Solve(StartX + Cur, StartY);
	if (Ret)
		return Ret;
	/* ���� �ȿ� ������ �̹� ���� ���� �ƴѰ�� */
	if (InRange(StartY + Cur) && !Visit[StartX][StartY + Cur])
		Ret = Solve(StartX, StartY + Cur);

	return Ret;
}