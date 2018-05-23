#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
[���� ����]

�� ���� 0 �̻� 10000 ������ �����̴�.


[�Է�]

���� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����, �� �Ʒ��� �� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� 10���� ���� �־�����.


[���]

����� �� ���� '#t'�� �����ϰ�, ������ �� ĭ �� ���� ������ ����Ѵ�.

(t�� �׽�Ʈ ���̽��� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�.)
*/

vector<int> Map;

int main()
{
	int TC;
	int Input;
	double Temp;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Temp = 0;
		Map.clear();
		for (int j = 0; j < 10; j++) {
			cin >> Input;
			Map.push_back(Input);
		}
		sort(Map.begin(), Map.end());
		for (int j = 1; j < Map.size() - 1; j++)
			Temp += Map.at(j);
		Input = (Temp / 8) + 0.5;
		printf("#%d %d\n", i, Input);
	}

	return 0;
}