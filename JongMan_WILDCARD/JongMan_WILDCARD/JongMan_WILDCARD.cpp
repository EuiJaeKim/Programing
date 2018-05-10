#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 10) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ���ϵ�ī�� ���ڿ� W �� �־�����, �� ���� �ٿ��� ���ϸ��� �� N (1 <= N <= 50) �� �־�����. �� �� N �ٿ� �ϳ��� �� ���ϸ��� �־�����. ���ϸ��� ���� ���� ���ĺ� ��ҹ��ڿ� ���ڸ����� �̷���� ������, ���ϵ�ī��� �� �ܿ� * �� ? �� ���� �� �ִ�. ��� ���ڿ��� ���̴� 1 �̻� 100 �����̴�.

���
�� �׽�Ʈ ���̽����� �־��� ���ϵ�ī�忡 ��ġ�Ǵ� ���ϵ��� �̸��� �� �ٿ� �ϳ��� �ƽ�Ű �ڵ� ����(����, �빮��, �ҹ��� ��)��� ����Ѵ�.
*/

string W; // ���ϵ�ī�� ���ڿ� W
string S;
bool Visit[100][100]; // ���ӵ� '*'�� ��Ʈ�ϱ� ���� 
bool Solve(int w, int s);

int main()
{
	int TC;
	int N; // ���ϸ��� �� N (1 <= N <= 50)
	vector<string> Res;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> W;
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int j = 0; j < 100; j++)
				for (int k = 0; k < 100; k++)
					Visit[j][k] = false;
			cin >> S;
			if (Solve(0, 0))
				Res.push_back(S);
		}
		if (Res.size() != 0) {
			sort(Res.begin(), Res.end());
			for (int j = 0; j < Res.size(); j++)
				cout << Res.at(j) << endl;
		}

		Res.clear();
	}

	return 0;
}

bool Solve(int w, int s)
{
	// '*'�� ���ӵɶ� ��Ʈ �ؾ���.. �ȱ׷� ������ ������
	if (Visit[w][s])
		return false;
	Visit[w][s] = true;
		// w, s�� ���ڿ� ���̺��� �۾ƾ��ϰ�.. W[w] �� S[s]�� ���ų� W[w]�� ? ������.
	while (W.size() > w && S.size() > s && (W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}
	// 1. ���� �����ߴ�?
	if (W.size() == w && S.size() == s)
		return true;
	// 2. ���� �ƴϸ� W[w]�� '*' ����?
	if (W[w] == '*') {
		// s �ڷ� ���� ��
		while (S.size() >= s) {
			if (Solve(w + 1, s))
				return true;
			s++;
		}
	}
	return false;
}