#include <iostream>
#include <string>

using namespace std;

/*
�Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. �� �� C�ٿ� �ϳ��� ���� Ʈ���� ������ �׸��� �־����ϴ�. ��� ���ڿ��� ���̴� 1,000 �����̸�, ���� �׸��� ũ��� 220 �� 220 �� ���� �ʽ��ϴ�.

���
�� �׽�Ʈ ���̽��� �� �ٿ� �־��� �׸��� ���Ϸ� ������ ����� ���� Ʈ�� �����ؼ� ����մϴ�.
*/

string Solve(string& str, int& Cur);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		string Input;
		int Cur = -1;
		cin >> Input;
		cout << Solve(Input, Cur) << endl;
	}

	return 0;
}

string Solve(string& str, int& Cur)
{
	Cur++;
	// b�� w�� ����.
	if (str[Cur] == 'b' || str[Cur] == 'w')
		return string(1, str[Cur]);
	/*
	x�� ���
	1 2 > 3 4
	3 4 > 1 2
	*/

	string First = Solve(str, Cur); // ù��° ĭ�� �ϼ��ؼ� ����
	string Second = Solve(str, Cur);// �ι�° ĭ�� �ϼ��ؼ� ����
	string Third = Solve(str, Cur);// ����° ĭ�� �ϼ��ؼ� ����
	string Fourth = Solve(str, Cur);// �׹�° ĭ�� �ϼ��ؼ� ����

	return "x" + Third + Fourth + First + Second; // ���� �ٲ��ֱ�.
}