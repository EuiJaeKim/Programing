#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(A,B) A>B ? B : A

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 50) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���� N (1 <= N <= 100), ����� ������ �� S (1 <= S <= 10) �� �־�����. �� ���� �ٿ� N���� ������ ������ ���ڵ��� �־�����. ������ ��� ���� 1000 ������ �ڿ����̴�.

���
�� �׽�Ʈ ���̽�����, �־��� ������ �ִ� S ���� ���� ����ȭ�� �� ���� ������ ���� �ּҰ��� ����Ѵ�.
*/

vector<int> Arr;
int N, S;/* ������ ���� N (1 <= N <= 100), ����� ������ �� S (1 <= S <= 10) */
int SelectArr[11][2] = { 0, }; /* 1��° ���� ���� ���� 2��° ���� ���� */
int Min;
void Solve(int StartX, int GroupNum);
void MinCal();

int main()
{
	int TC;
	int Input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Min = 987654321;
		cin >> N >> S;
		Arr.clear();
		for (int j = 0; j < N; j++) {
			cin >> Input; /* ������ ��� ���� 1000 ������ �ڿ��� */
			Arr.push_back(Input);
		}
		sort(Arr.begin(), Arr.end());
		Solve(0, 0);
		cout << Min << endl;
	}
	return 0;
}

void Solve(int StartX, int GroupNum)
{
	if (GroupNum == S) {
		MinCal();
		return;
	}

	SelectArr[GroupNum][0] = StartX;
	if (GroupNum < S-1) {
		for (int i = 1; N - (StartX + i) >= S - GroupNum; i++) { /* i�� Group�� ũ�� */
			SelectArr[GroupNum][1] = i;
			Solve(StartX + i, GroupNum + 1);
		}
	}
	else {
		SelectArr[GroupNum][1] = N - StartX-1;
		Solve(N, GroupNum + 1);
	}
}

void MinCal()
{
	int Sum, Temp;

	Sum = 0;
	for (int i = 0; i < S; i++) {
		Temp = 0;
		for (int j = 0; j < SelectArr[i][1]; j++) {
			Temp += Arr[SelectArr[i][0] + i];
		}
		Temp = (int)(0.5 + (double)(Temp / SelectArr[i][1]));
		/* �׷� ���� ���ڵ��� ���ؼ� ����� ��ŭ ���� ���� ���� ������ ���� ����. 0.5 ���ִ°� �ݿø�ó��  */
		Sum += Temp;
	}

	Min = MIN(Min, Sum);
}