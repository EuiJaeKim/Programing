#include <iostream>

using namespace std;

/*
�Է�
ù° �ٿ� �巡�� Ŀ���� ���� N(1 �� N �� 20)�� �־�����. ��° �ٺ��� N���� �ٿ��� �巡�� Ŀ���� ������ �־�����. �巡�� Ŀ���� ������ �� ���� x, y, d, g�� �̷���� �ִ�. x�� y�� �巡�� Ŀ���� ���� ��, d�� ���� ����, g�� �����̴�. (0 �� x, y �� 100, 0 �� d �� 3, 0 �� g �� 10)

�Է����� �־����� �巡�� Ŀ��� ���� ������ ����� �ʴ´�. �巡�� Ŀ��� ���� ��ĥ �� �ִ�.

������ 0, 1, 2, 3 �� �ϳ��̰�, ������ �ǹ��Ѵ�.

0: x��ǥ�� �����ϴ� ���� (��)
1: y��ǥ�� �����ϴ� ���� (��)
2: x��ǥ�� �����ϴ� ���� (��)
3: y��ǥ�� �����ϴ� ���� (��)
���
ù° �ٿ� ũ�Ⱑ 1��1�� ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���� ������ ����Ѵ�.
*/

#define MAX 101

int Map[MAX][MAX] = { 0, }; /* 0 �� x, y �� 100 */
int GenCout[11] = { 1,1,2,4,8,16,32,64,128,256,512 };
int G; /* 0 �� g �� 10 */
int Gen[11][512] = { 0, }; // �� ���� ���� D �� ����  

void Solve(int CurX, int CurY, int Gen[11][512]);
void Move(int& X, int& Y, int D);
int CalCount();

int main()
{
	int X, Y, D, N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X >> Y >> D >> G;
		Gen[0][0] = D;
		Map[Y][X] = 1;
		Solve(X, Y, Gen);
	}
	cout << CalCount() << endl;
	return 0;
}

void Solve(int CurX, int CurY, int Gen[11][512])
{
	int CurGen;
	int CurD;
	int K; // n����� 0������ K�������� ���� ����.
	/* 1. 0���� ó�� */
	CurD = Gen[0][0];
	Move(CurX, CurY, CurD);

	/* 2. 1������� G������� ����.  */
	for (int i = 1; i <= G; i++) {
		CurGen = i - 1; // 1���븦 �׸����� 0���븦 �����ϰ�, 2���븦 �׸����� 1���븦 ���� 0���븦 �����ϱ� ������ ���� ������ �ϴ� ���� -1�� ����.
		K = 0;
		do {
			for (int j = GenCout[CurGen] - 1; j >= 0; j--) {
				CurD = Gen[CurGen][j] + 1; // �ð���� ȸ��.
				if (CurD == 4)// overflow ó��
					CurD = 0;

				Gen[i][K] = CurD; // ����
				Move(CurX, CurY, CurD);
				K++; // K ����
			}
			CurGen--;
		} while (CurGen >= 0);
	}
}

void Move(int& X, int& Y, int D)
{
	switch (D)
	{
	case 0: /* �� */
		Map[Y][++X] = 1;
		break;
	case 1: /* �� */
		Map[--Y][X] = 1;
		break;
	case 2: /* �� */
		Map[Y][--X] = 1;
		break;
	case 3: /* �� */
		Map[++Y][X] = 1;
		break;
	}
}

int CalCount()
{
	int Ret = 0;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (Map[i][j] == 1) {
				if (Map[i][j + 1] == 1 && Map[i + 1][j] == 1 && Map[i + 1][j + 1] == 1)
					Ret++;
			}
		}
	}

	return Ret;
}