#include <iostream>
#include <math.h>
#define MIN(A,B) A>B ? B : A

using namespace std;

/*
�Է�
ù° �ٿ� N(2 �� N �� 50)�� M(1 �� M �� 13)�� �־�����.

��° �ٺ��� N���� �ٿ��� ������ ������ �־�����.

������ ������ 0, 1, 2�� �̷���� �ְ�, 0�� �� ĭ, 1�� ��, 2�� ġŲ���� �ǹ��Ѵ�. ���� ������ 2N���� ���� ������, ��� 1���� �����Ѵ�. ġŲ���� ������ M���� ũ�ų� ����, 13���� �۰ų� ����.

���
ù° �ٿ� �����Ű�� ���� ġŲ���� �ִ� M���� ����� ��, ������ ġŲ �Ÿ��� �ּҰ��� ����Ѵ�.
*/
int N, M; /* N(2 �� N �� 50),  M(1 �� M �� 13) */
int Home[100][2] = { 0, };
int Chicken[13][2] = { 0 , };
int SelectChicken[13] = { 0, };
int HomeCount;
int ChickenCount;
int Min;

void isMin();
void Solve(int CurCount, int SelectCount);

int main()
{
	int Input;

	cin >> N >> M;
	HomeCount = ChickenCount = 0;
	Min = 987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Input;
			if (Input == 1) {
				Home[HomeCount][0] = i;
				Home[HomeCount++][1] = j;
			}
			else if (Input == 2) {
				Chicken[ChickenCount][0] = i;
				Chicken[ChickenCount++][1] = j;
			}
		}
	}
	Solve(0, 0);
	cout << Min << endl;
	return 0;
}

void Solve(int CurCount, int SelectCount)
{
	/* Base Case */
	if (SelectCount == M) {
		isMin();
		return;
	}

	for (int i = CurCount; i < ChickenCount; i++) {
		SelectChicken[SelectCount] = i;
		Solve(i + 1, SelectCount + 1);
	}
}

void isMin()
{
	int Ret = 0, min;
	int Temp;
	for (int i = 0; i < HomeCount; i++) {
		min = 987654321;
		for (int j = 0; j < M; j++) {
			Temp = abs(Home[i][0] - Chicken[SelectChicken[j]][0]) + abs(Home[i][1] - Chicken[SelectChicken[j]][1]);
			min = MIN(min, Temp);
		}
		Ret += min;
	}
	Min = MIN(Ret, Min);
}