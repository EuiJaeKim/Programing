#include <iostream>
#include <string>

using namespace std;

/*

[���� ����]

�� ���ڿ��� ���̴� 30�̴�. ������ �ִ� ���̴� 10�̴�.


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���̰� 30�� ���ڿ��� �־�����.


[���]

����� �� ���� '#t'�� �����ϰ�, ������ �� ĭ �� ���� ������ ����Ѵ�.

*/

string Input;
char Minstr[10];

int Solve();
bool Check(int Length);

int main()
{
	int TC;
	
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> Input;

		printf("#%d %d\n",i, Solve());

		Input.clear();
	}

	return 0;
}

int Solve()
{
	Minstr[0] = Input[0];

	for (int i = 1; i < 10; i++) {
		if (Input[i] == Minstr[0])
			if (Check(i))
				return i;
		Minstr[i] = Input[i];
	}
	return 10;
}

bool Check(int Length)
{
	int Cur = 0;
	for (int i = 0; i < 30; i++) {
		if (Minstr[Cur] != Input[i])
			return false;
		Cur++;
		if (Cur == Length)
			Cur = 0;
	}
	return true;
}