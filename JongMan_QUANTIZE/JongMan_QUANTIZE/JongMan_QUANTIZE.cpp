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
int Cache[101][11];
int QSum[101] = { 0, }; /* ������ */
int PSum[101] = { 0, }; /* ������ �� ������ �� */
int Min;

int Solve(int StartX, int GroupNum);
int quantize(int from, int parts);
int MinCal(int GroupCount);
void Init();

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
		Init();
		cout << Solve(0, 0) << endl;

	}
	return 0;
}

void Init()
{
	sort(Arr.begin(), Arr.end());
	QSum[0] = Arr[0];
	PSum[0] = Arr[0] * Arr[0];
	for (int i = 1; i < N; i++) {
		QSum[i] = QSum[i - 1] + Arr[i];
		PSum[i] = PSum[i - 1] + (Arr[i] * Arr[i]);
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 11; j++)
			Cache[i][j] = -1;
}

int Solve(int StartX, int GroupNum)
{
	/* base case Cache���� �ִٸ� ����. */
	if (Cache[StartX][GroupNum] != -1)
		return Cache[StartX][GroupNum];

	/* �ƴҰ�� ����Ѵ�. */
	SelectArr[GroupNum][0] = StartX;
	if (StartX != N && GroupNum == S - 1) { // ������ �׷��� ���.�ε� ������ �׷��ε�? StartX == N�̸�? ����? ���� �׷� ���ݽô�
		SelectArr[GroupNum][1] = N - StartX;
		Cache[StartX][GroupNum] = MinCal(GroupNum);
	}
	else if (StartX == N)
		return 0;
	else {
		Cache[StartX][GroupNum] = 987654321;
		for (int i = 1; StartX + i <= N; i++) {
			SelectArr[GroupNum][1] = i;
			Cache[StartX][GroupNum] = MIN(Cache[StartX][GroupNum], MinCal(GroupNum) + Solve(StartX + i, GroupNum + 1));
		}
	}
	return Cache[StartX][GroupNum];
}

int MinCal(int GroupCount)
{
	int Sum, MiddleValue, SumTemp, PSumTemp;

	/* SumTemp�� �׷쳻�� ���� �� ���� ��. */
	SumTemp = QSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : QSum[SelectArr[GroupCount][0] - 1]);
	PSumTemp = PSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : PSum[SelectArr[GroupCount][0] - 1]);
	/* �׷� ���� ���ڵ��� ���ؼ� ����� ��ŭ ���� ���� ���� ������ ���� ����. 0.5 ���ִ°� �ݿø�ó��  */
	MiddleValue = (int)(0.5 + ((double)SumTemp / (double)SelectArr[GroupCount][1]));

	Sum = PSumTemp - (2 * MiddleValue*SumTemp) + (MiddleValue*MiddleValue*SelectArr[GroupCount][1]);
	/* ���� ������ �� */
	return Sum;
}