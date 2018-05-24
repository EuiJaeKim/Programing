#include <iostream>
#include <string.h>

using namespace std;

/*
[�Է�]

ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �ϳ��� �ڿ��� N(1 �� N �� 10)�� �־�����.


[���]

�� �׽�Ʈ ���̽����� ��#x ��(x�� �׽�Ʈ���̽� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�)�� ����ϰ�, �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.
*/

int N;
int Map[11] = { 0, };
int XArray[11] = { 0, };

void Init();
void dfs(int Max, int Cur);
bool IsPossible(int Max, int Cur, int Val);

int main()
{
	int TC;

	cin >> TC;
	Init();

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		printf("#%d %d\n", i, Map[N]);
	}
}

void Init()
{
	for (int i = 1; i <= 10; i++) {
		memset(XArray,-1, sizeof(XArray));
		dfs(i, 0);
	}
}

void dfs(int Max, int Cur)
{// cur�� �� �Ʒ� y��
	if (Max == Cur) {
		Map[Max]++;
		return;
	}

	for (int i = 0; i < Max; i++) { // i�� ���� ������ x��
		if (IsPossible(Max, Cur, i)) {
			XArray[i] = Cur;
			dfs(Max, Cur + 1);
			XArray[i] = -1;
		}
	}
}

bool IsPossible(int Max, int Cur, int Val) // Cur�� y�� Val�� x��
{
	if (XArray[Val] != -1)
		return false;
	for (int i = 1; Cur - i >= 0; i++) {
		if (Val - i >= 0 && XArray[Val - i] == Cur - i)
			return false;
		if (Val + i < Max && XArray[Val + i] == Cur - i)
			return false;
	}
	return true;
}