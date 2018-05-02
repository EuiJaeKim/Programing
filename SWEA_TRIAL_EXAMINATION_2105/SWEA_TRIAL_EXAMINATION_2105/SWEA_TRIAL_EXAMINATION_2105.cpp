#include <cstdio>
int Map[20][20] = { 0 };
int Desert[101] = { 0 };
int N;
int Result;

void Solve();
int RangeCheck(int X, int Y);
void DesertInit();


int main()
{
	int T, i, j, k;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &Map[j][k]);
			}
		}
		Result = -1;
		Solve();
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Solve()
{
	int i, j, x, y, CurI, CurJ, Temp, Flag;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (x = 1; x < N; x++) {
				for (y = 1; y < N; y++) {
					if (RangeCheck(i + x, j + x) && RangeCheck(i + y, j - y) && RangeCheck(i + x + y, j) && Result < (x + y) * 2) { // �簢���� �����ϴ�? �����ϸ� �ѷ��� �������� ū�Ŵ�? ������ ������ �ߺ��̰� ���� �ʿ���ŵ�.
						DesertInit();
						CurI = i;
						CurJ = j;
						Flag = 0;

						for (Temp = 0; Temp < x; Temp++) {
							CurI++;
							CurJ++;
							if (Desert[Map[CurI][CurJ]] == 0)// �ȸԾ����Ÿ�
								Desert[Map[CurI][CurJ]] = 1; //�����ŷ� üũ�ϰ�
							else {// �Ծ����Ÿ� 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // �Ծ����Ű� �ִ� �����ض�

						for (Temp = 0; Temp < y; Temp++) {
							CurI++;
							CurJ--;
							if (Desert[Map[CurI][CurJ]] == 0)// �ȸԾ����Ÿ�
								Desert[Map[CurI][CurJ]] = 1; //�����ŷ� üũ�ϰ�
							else {// �Ծ����Ÿ� 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // �Ծ����Ű� �ִ� �����ض�

						for (Temp = 0; Temp < x; Temp++) {
							CurI--;
							CurJ--;
							if (Desert[Map[CurI][CurJ]] == 0)// �ȸԾ����Ÿ�
								Desert[Map[CurI][CurJ]] = 1; //�����ŷ� üũ�ϰ�
							else {// �Ծ����Ÿ� 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // �Ծ����Ű� �ִ� �����ض�

						for (Temp = 0; Temp < y; Temp++) {
							CurI--;
							CurJ++;
							if (Desert[Map[CurI][CurJ]] == 0)// �ȸԾ����Ÿ�
								Desert[Map[CurI][CurJ]] = 1; //�����ŷ� üũ�ϰ�
							else {// �Ծ����Ÿ� 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // �Ծ����Ű� �ִ� �����ض�

						Result = (x + y) * 2;
					}
				}
			}
		}
	}
}

int RangeCheck(int X, int Y)
{
	if (X >= 0 && X < N && Y >= 0 && Y < N)
		return 1;
	else
		return 0;
}

void DesertInit()
{
	for (int i = 0; i < 101; i++)
		Desert[i] = 0;
}