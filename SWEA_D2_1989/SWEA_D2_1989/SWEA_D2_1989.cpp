#include <iostream>
#include <string>

using namespace std;

/*
[���� ����]

�� �ܾ��� ���̴� 3 �̻� 10 �����̴�.


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ� �ϳ��� �ܾ �־�����.


[���]

����� �� ���� '#t'�� �����ϰ�, ������ �� ĭ �� ���� ������ ����Ѵ�.
*/

string Map;

int Solve();

int main()
{
	int TC;
	cin >> TC;


	for (int i = 1; i <= TC; i++) {
		cin >> Map;
		printf("#%d %d\n",i,Solve());
		Map.clear();
	}
}

int Solve()
{
	int j = Map.size()-1;
	for (int i = 0; i < j; i++) {
		if (Map.at(i) != Map.at(j))
			return 0;
		j--;
	}
	return 1;
}