#include <cstdio>
#include <cstdlib>
#include <cstring>

int Num[10] = { 0 };
int NumCount;

int Solve(int S);

int main()
{
	int TC;
	int Temp;
	int Input;

	scanf("%d", &TC);

	for (register int i = 1; i <= TC; i++) {
		NumCount = 0;
		for (register int j = 0; j < 10; j++) {
			scanf("%d", &Temp);
			if (Temp == 1)
				Num[NumCount++] = j;
		}
		scanf("%d", &Input);
		Temp = Solve(Input);
		if (Temp == -1)
			printf("#%d -1\n", i);
		else
			printf("#%d %d\n", i, Temp + 1);
	}
	return 0;
}

int Solve(int S)
{
	int *Insu;
	int Count = 0;
	int Flag = 0;
	int Temp = 0;
	int Tmp;
	int Length;
	int Min;
	char NumMax[8];
	/* 1 */
	sprintf(NumMax, "%d", S);
	//itoa(S, NumMax, 10);
	Length = strlen(NumMax);
	for (register int i = 0; i < Length; i++) {
		for (register int j = 0; j < NumCount; j++)
			if (NumMax[i] - '0' == Num[j])
				Flag++;
	}

	if (Flag == Length)
		return Flag;
	/* 1 */

	/* 2 */
	for (register int i = 2; i <= S / 2; i++) { // ���μ����� �ؼ� ���� ã��
		if (S %i == 0)
			Count++;
	}
	Insu = (int*)malloc(sizeof(int)*Count); // ������ŭ �迭 �Ҵ�
	for (register int i = 2; i <= S / 2; i++) { // ����� ����
		if (S %i == 0)
			Insu[Temp++] = S / i;
	}
	/* 2 */
	Min = 10000;
	/* 3 */
	for (register int i = 0; i < Count; i++) { // ���� ū ������� �˻��ϸ鼭 ����� �ִ� ���� ã��
		sprintf(NumMax, "%d", Insu[i]);
		//itoa(Insu[i], NumMax, 10);
		Length = strlen(NumMax);
		Flag = 0;
		Tmp = 0;

		for (register int k = 0; k < Length; k++) {// ���� ������ ���̸�ŭ �˻�
			for (register int j = 0; j < NumCount; j++) { // ���⿡�� ������ �ִ� �� ��ŭ �˻�
				if (NumMax[k] - '0' == Num[j]) {//������������ Flag=1
					Flag = 1;
					break;
				}
			}
			if (Flag == 1) {// ���巯��
				Flag = 0;
				Tmp++;
			}
			else {
				Flag = -1;
				break;
			}
		}

		if (Flag != -1 && Tmp == Length) {// ã����
			Temp = Solve(S / Insu[i]) + 1;
			if (Temp != 0) {
				if (Min > Temp + Length)
					Min = Temp + Length;
			}
		}
	}
	/* 3 */
	/* 4 */
	free(Insu);
	if (Min == 10000)
		return -1;
	else
		return Min;
	/* 4 */
}