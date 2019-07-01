#include <iostream>
using namespace std;

#define Leng 30000
int Cmp[5][30000][5];
int makeBlock(int module[][4][4])
{
	int CmpLength[20] = { 0, };
	int Val, Max, Min, Ret = 0;
	bool Check;
	for (register int i = 0; i < Leng; i++) {
		Max = 0;
		Min = 1000;
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (Max < module[i][x][y])
					Max = module[i][x][y];
				if (Min > module[i][x][y])
					Min = module[i][x][y];
			}
		}
		Cmp[Max - Min][CmpLength[Max - Min]][0] = i; // ���° �������
		Cmp[Max - Min][CmpLength[Max - Min]][1] = Min; // ����� ���� ���� ����
		Cmp[Max - Min][CmpLength[Max - Min]][2] = Max; // ����� ���� ���� ����
		Cmp[Max - Min][CmpLength[Max - Min]][3] = -1; // ���� ¦�� �Ǵ� ����� ��ȣ
		Cmp[Max - Min][CmpLength[Max - Min]++][4] = -1; // ���� ¦�� �Ǵ� ������ ���� ��
	}

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < CmpLength[i]; j++) {
			for (int k = 0; k < CmpLength[i]; k++) {
				if (j != k) {
					if (Cmp[i][j][3] != -1) {// ���� ¦�� �Ǵ� ���� ������
						if (Cmp[i][j][1] + Cmp[i][k][2] > Cmp[i][j][4]) {// ���� ���� ���� ũ�⸸ ���ؼ� �� Ŭ���� ���.
							Check = false;
							Val = module[Cmp[i][j][0]][0][0] + module[Cmp[i][k][0]][0][3];
							for (int x = 0; x < 4; x++) {
								for (int y = 0; y < 4; y++) {
									if (module[Cmp[i][j][0]][x][y] + module[Cmp[i][k][0]][x][3 - y] != Val) {
										Check = true;
										break;
									}
								}
								if (Check)
									break;
							}
							if (!Check) { // ¦�� �Ǵ� ����� ã��
								if (Cmp[i][j][3] != -1) 
									Ret -= Cmp[i][j][4];
								Cmp[i][j][3] = Cmp[i][k][0];
								Cmp[i][k][3] = Cmp[i][j][0];
								Cmp[i][j][4] = Cmp[i][k][4] = Cmp[i][j][1] + Cmp[i][k][2];
								Ret += Cmp[i][j][4];
							}
						}
					}
					else {// ���� ¦�� �Ǵ� ���� ������
						// �׳� ���
						Check = false;
						Val = module[Cmp[i][j][0]][0][0] + module[Cmp[i][k][0]][0][3];
						for (int x = 0; x < 4; x++) {
							for (int y = 0; y < 4; y++) {
								if (module[Cmp[i][j][0]][x][y] + module[Cmp[i][k][0]][x][3 - y] != Val) {
									Check = true;
									break;
								}
							}
							if (Check)
								break;
						}
						if (!Check) { // ¦�� �Ǵ� ����� ã��
							Cmp[i][j][3] = Cmp[i][k][0];
							Cmp[i][k][3] = Cmp[i][j][0];
							Cmp[i][j][4] = Cmp[i][k][4] = Cmp[i][j][1] + Cmp[i][k][2];
							Ret += Cmp[i][j][4];
						}
					}
				}
			}
		}
	}
	return Ret;
}