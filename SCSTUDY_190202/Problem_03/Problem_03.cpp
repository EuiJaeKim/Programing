#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int M; // �̵��ð� 20 �� M �� 100
int Move[2][100]; // 0 �̵����� 1 �� 2 ������ 3 �Ʒ� 4 ����
int BC[8][4]; // Battery Charger 0 X 1 Y 2 ���� 3 ����(¦��)
int BCCount; // Battery Charger ���� �ְ� 8��.
int Human[2][2];

void Init();
void HumanMove(int Val);
int Solve();

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Init();
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

void Init()
{
	cin >> M;
	cin >> BCCount;

	memset(Move, 0, 2 * 100);
	memset(BC, 0, 8 * 4);

	Human[0][0] = Human[0][1] = 1;
	Human[1][0] = Human[1][1] = 10;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Move[i][j];
		}
	}

	for (int i = 0; i < BCCount; i++) {
		cin >> BC[i][1] >> BC[i][0] >> BC[i][2] >> BC[i][3];
	}
}

void HumanMove(int Val)
{
	for (int i = 0; i < 2; i++) {
		switch (Move[i][Val])
		{
		case 0:
			break;
		case 1:
			Human[i][0]--;
			break;
		case 2:
			Human[i][1]++;
			break;
		case 3:
			Human[i][0]++;
			break;
		case 4:
			Human[i][1]--;
			break;
		}
	}

}

int Solve()
{
	int Time = 0;
	int ConnectPossible[2][8];// �ð����� ��� A, ���B�� ������ �� �ִ� BC�� �迭
	int BPower[2][8];
	int ConnectCount[2];
	int AMax, BMax, AMaxP, BMaxP;
	int Result = 0;
	int TempA, TempB, TempAP, TempBP;

	while (Time <= M)
	{
		AMax = BMax = AMaxP = BMaxP = 0;
		TempA = TempB = TempAP = TempBP = 0;

		memset(ConnectPossible, -1, sizeof(ConnectPossible));
		memset(BPower, 0, sizeof(BPower));

		ConnectCount[0] = ConnectCount[1] = 0;
		// 1. �� ������� ���� �� �� �ִ� BC�� ConnectPossible�迭�� ����
		for (int i = 0; i < BCCount; i++) {
			if (abs(Human[0][0] - BC[i][0]) + abs(Human[0][1] - BC[i][1]) <= BC[i][2]) { // ��� A�� ���� �ȿ� ���ٸ�
				ConnectPossible[0][ConnectCount[0]++] = i;
			}
			if (abs(Human[1][0] - BC[i][0]) + abs(Human[1][1] - BC[i][1]) <= BC[i][2]) { // ��� B�� ���� �ȿ� ���ٸ�
				ConnectPossible[1][ConnectCount[1]++] = i;
			}
		}
		// ConnectPossible�� P ���� BPower �迭�� �Ȱ��� ������� ����.
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < ConnectCount[i]; j++) {
				BPower[i][j] = BC[ConnectPossible[i][j]][3];
				// BC�� P�� ���� ������ ����
				if (i == 0 && AMaxP <= BPower[i][j]) {
					if (AMaxP != 0) {
						TempA = AMax;
						TempAP = AMaxP;
					}
					AMax = j;
					AMaxP = BPower[i][j];
				}
				else if (i == 0 && TempAP <= BPower[i][j]) {
					TempA = j;
					TempAP = BPower[i][j];
				}
				else if (i == 1 && BMaxP <= BPower[i][j]) {
					if (BMaxP != 0) {
						TempB = BMax;
						TempBP = BMaxP;
					}
					BMax = j;
					BMaxP = BPower[i][j];
				}
				else if (i == 1 && TempBP <= BPower[i][j]) {
					TempB = j;
					TempBP = BPower[i][j];
				}
			}
		}

		if (AMaxP != BMaxP || AMax != BMax) {
			Result += AMaxP + BMaxP;
		}
		else if (AMax == BMax) {// 2. Ȥ�� �λ�� �� �Ѹ��� �ٸ� BC�� ������ ���͸� �����ѷ��� �þ���� �˻�.
			if (TempAP != 0 && TempBP != 0) { // �ΰ� �� second�� ����
				if (TempAP > TempBP) {
					if (TempAP > AMaxP / 2)
						Result += TempAP + BMaxP;
					else
						Result += AMaxP / 2;
				}
				else {
					if (TempBP > BMaxP / 2)
						Result += AMaxP + TempBP;
					else
						Result += BMaxP / 2;
				}
			}
			else if (TempAP != 0) {
				if (TempAP > AMaxP / 2)
					Result += TempAP + BMaxP;
				else
					Result += AMaxP / 2;
			}
			else if (TempBP != 0) {
				if (TempBP > BMaxP / 2)
					Result += AMaxP + TempBP;
				else
					Result += BMaxP / 2;
			}
			else { // �� �� second�� ����
				Result += AMaxP / 2;
			}
		}
		HumanMove(Time++);
	}
	return Result;
}