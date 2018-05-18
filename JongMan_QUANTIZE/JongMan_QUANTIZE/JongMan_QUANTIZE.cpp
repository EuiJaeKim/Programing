#include <iostream>
#include <vector>
#include <math.h>
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
int Cache[101][11] = { 0, };
int QSum[11] = { 0, }; /* ������ */
int PSum[11] = { 0, }; /* ������ �� ������ �� */
int Min;

int Solve(int StartX, int GroupNum);
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
			Cache[i][j] = 0;
}

int Solve(int StartX, int GroupNum)
{


	/* �ӵ� �����ϱ�
	StartX �� GroupNum �������� Cache ���� ������
	���ϰ� int�� �����ϰ�.
	StartX �ִ� 100�̴ϱ� 101,
	GroupNum �ִ� 10�̴ϱ� 11.

	�ٽ� ¥.
	*/












	if (GroupNum > 0 && SelectArr[GroupNum - 1][0] + SelectArr[GroupNum - 1][1] == N)
		return MinCal(GroupNum);

	SelectArr[GroupNum][0] = StartX;
	if (GroupNum < S - 1) {
		for (int i = 1; StartX + i <= N; i++) { /* i�� Group�� ũ�� */
			SelectArr[GroupNum][1] = i;
			Solve(StartX + i, GroupNum + 1);
		}
	}
	else {
		SelectArr[GroupNum][1] = N - StartX;
		MinCal(GroupNum);
		Solve(N, GroupNum + 1);
	}
}

int MinCal(int GroupCount)
{
	int Sum, MiddleValue, SumTemp, PSumTemp;

	Sum = 0;
	/* SumTemp�� �׷쳻�� ���� �� ���� ��. */
	SumTemp = QSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : QSum[SelectArr[GroupCount][0] - 1]);
	PSumTemp = PSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : PSum[SelectArr[GroupCount][0] - 1]);
	/* �׷� ���� ���ڵ��� ���ؼ� ����� ��ŭ ���� ���� ���� ������ ���� ����. 0.5 ���ִ°� �ݿø�ó��  */
	MiddleValue = (int)(0.5 + ((double)SumTemp / (double)SelectArr[GroupCount][1]));

	Sum += PSumTemp - (2 * MiddleValue*SumTemp) + (MiddleValue*MiddleValue*SelectArr[GroupCount][1]);
	/* ���� ������ �� */

	Min = MIN(Min, Sum);
}