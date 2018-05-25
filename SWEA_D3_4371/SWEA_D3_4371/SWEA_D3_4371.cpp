#include <iostream>
#include <vector>

using namespace std;

/*
[�Է�]
ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ� ��ſ� ���� �� N�� �־�����. (2 �� N �� 5000)

�� �׽�Ʈ ���̽��� �� ��° �ٺ��� N���� �ٿ� ���� ��ſ� ���� ������ ������������ ���ĵǾ� �־�����.

�����ϴ� ���� �׻� 1���̰�, ������ ���� 109���� ���� ���̴�.

[���]
�� �׽�Ʈ ���̽����� �ױ��� �鷶�� ���� �ּ� ���� ����Ѵ�.
*/
int N;
vector<int> Map;

int main()
{
	int TC;
	int Input;
	bool IsExist;
	int Res;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Map.clear();
		cin >> N;
		cin >> Input;
		Res = 0;
		IsExist = false;
		for (int j = 1; j < N; j++) {
			cin >> Input;
			for (int k = 0; k < Map.size(); k++) {
				if ((Input-1)%Map.at(k) == 0) {
					IsExist = true;
					break;
				}
			}
			if (!IsExist) {
				Map.push_back(Input-1);
				Res++;
			}
			else
				IsExist = false;
		}
		printf("#%d %d\n", i,Res);
	}

	return 0;
}