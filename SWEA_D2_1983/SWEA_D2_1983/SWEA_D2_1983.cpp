#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // N�� �׻� 10�� ����̸�, 10�̻� 100������ �����̴�. (10 �� N �� 100)
int K; // K�� 1 �̻� N ������ �����̴�. (1 �� K �� N), K ��° �л��� ������ �ٸ� �л��� ������ ������ ���� �Է����� �־����� �ʴ´�.
vector<int> Students;
int KScore;

void Init();
void Solve();

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N >> K;
		Init();

		printf("#%d ", i);
		Solve();
	}

	return 0;
}

void Init()
{
	int Middle, Final, Homework;
	Students.clear();
	for (int i = 0; i < N; i++) {
		cin >> Middle >> Final >> Homework;
		Students.push_back(Middle * 35 + Final * 45 + Homework * 20);
	}
	KScore = Students[K - 1];
	sort(Students.begin(), Students.end());
}

void Solve()
{
	int Rank;

	for (int i = Students.size() - 1; i >= 0; i--) {
		if (Students[i] == KScore) {
			Rank = Students.size() - i;
			break;
		}
	}
	if (Rank <= (N / 10))
		cout << "A+" << endl;
	else if (Rank <= 2 * (N / 10))
		cout << "A0" << endl;
	else if (Rank <= 3 * (N / 10))
		cout << "A-" << endl;
	else if (Rank <= 4 * (N / 10))
		cout << "B+" << endl;
	else if (Rank <= 5 * (N / 10))
		cout << "B0" << endl;
	else if (Rank <= 6 * (N / 10))
		cout << "B-" << endl;
	else if (Rank <= 7 * (N / 10))
		cout << "C+" << endl;
	else if (Rank <= 8 * (N / 10))
		cout << "C0" << endl;
	else if (Rank <= 9 * (N / 10))
		cout << "C-" << endl;
	else
		cout << "D0" << endl;
}