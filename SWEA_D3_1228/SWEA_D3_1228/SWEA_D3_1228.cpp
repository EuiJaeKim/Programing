#include <cstdio>
#include <cstdlib>
#include <cstring>
int Map[20];
int MapS[20];
int Count;
int InstCount;
int Flag;

char InputString[550];

void Solve();

int main()
{
	char* Temp;

	for (int TC = 1; TC <= 10; TC++) {
		gets(InputString);
		Count = atoi(InputString);// ���� ��ȣ�� ����
		gets(InputString);
		Temp = strtok(InputString, " ");
		for (int i = 0; i < Count; i++) {
			Map[i] = atoi(Temp);
			Temp = strtok(NULL, " ");// ���� ��ȣ��
		}
		gets(InputString);
		InstCount = atoi(InputString);// ��ɾ��� ����

		Solve();
		printf("#%d ", TC);
		if (!Flag) {
			printf("%d %d %d %d %d %d %d %d %d %d\n", Map[0], Map[1], Map[2], Map[3], Map[4], Map[5], Map[6], Map[7], Map[8], Map[9]);
		}
		else {
			printf("%d %d %d %d %d %d %d %d %d %d\n", MapS[0], MapS[1], MapS[2], MapS[3], MapS[4], MapS[5], MapS[6], MapS[7], MapS[8], MapS[9]);
		}
	}


	return 0;
}

void Solve()
{
	char* Temp;
	char Inst;
	int x, y, s;

	Flag = 0;
	gets(InputString);
	Temp = strtok(InputString, " ");
	for (int i = 0; i < InstCount; i++) {
		Inst = Temp[0];// ��ɾ��� ����
		Temp = strtok(NULL, " ");
		x = atoi(Temp);// ��ɾ� ���� ��ġ
		Temp = strtok(NULL, " ");
		y = atoi(Temp);// ��ɾ� ���� ����

		if (x > 9) {
			for (int j = 0; j < y; j++)
				Temp = strtok(NULL, " ");
		}
		else {
			if (!Flag) {
				for (int j = 0; j < x; j++) // x�������� �׳� ����
					MapS[j] = Map[j];

				for (int j = 0; j < y; j++) {// x���ʹ� y������ �ְ�
					if (x + j < 10) {
						Temp = strtok(NULL, " ");
						s = atoi(Temp);// y�� ��ŭ �޾Ƽ�
						MapS[x + j] = s;
					}
					else
						Temp = strtok(NULL, " ");
				}
				if (x + y < 9) {
					for (int j = x; j + y <= 9; j++) {
						MapS[j + y] = Map[j];
					}
				}
				Flag = 1;
			}
			else {

				for (int j = 0; j < x; j++)
					Map[j] = MapS[j];

				for (int j = 0; j < y; j++) {
					if (x + j < 10) {
						Temp = strtok(NULL, " ");
						s = atoi(Temp);// y�� ��ŭ �޾Ƽ�
						Map[x + j] = s;
					}
					else
						Temp = strtok(NULL, " ");
				}
				if (x + y < 9) {
					for (int j = x; j + y <= 9; j++) {
						Map[j + y] = MapS[j];
					}
				}
				Flag = 0;
			}
		}
		Temp = strtok(NULL, " ");
	}
}