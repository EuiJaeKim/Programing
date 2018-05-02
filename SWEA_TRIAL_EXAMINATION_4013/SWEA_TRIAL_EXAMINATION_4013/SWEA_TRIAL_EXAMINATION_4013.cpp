#include <stdio.h>
#include <math.h>
#define Mirror(a) a==1?-1:1

int Magnet[4][8]; // N ���� 0 ����, S ���� 1
int Pointer[4];
int K; // �ڼ��� ȸ����Ű�� Ƚ��

void Solve(int Tar, int Rot, int Strt);
void Swap(int *A, int *B);

int main()
{
	int TC;
	int Start;
	int Rocate;
	int Result;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		Result = 0;
		scanf("%d", &K);
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++)
				scanf("%d", &Magnet[j][k]);
			Pointer[j] = 0;
		}

		for (int j = 0; j < K; j++) {
			scanf("%d", &Start);
			scanf("%d", &Rocate);
			Solve(Start - 1, Rocate, 1);
		}
		for (int j = 0; j < 4; j++) {
			if (Magnet[j][Pointer[j]] == 1)
				Result += (int)pow((double)2, (double)j);
		}
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Solve(int Tar, int Rot, int Strt) // Strt : 1�̸� ��ŸƮ 2�̸� ���� 3�̸� ������
{
	int Temp = Pointer[Tar];

	Pointer[Tar] -= Rot;
	if (Pointer[Tar] < 0)
		Pointer[Tar] = 7;
	else if (Pointer[Tar] > 7)
		Pointer[Tar] = 0;

	if (Strt == 1) {// �������̸� 2,3���϶� �翷����
		if (Tar == 1 || Tar == 2) {
			Swap(&Temp, &Pointer[Tar]);
			int Left, Right, LR, RL;
			Left = Pointer[Tar] - 2;
			Right = Pointer[Tar] + 2;
			LR = Pointer[Tar - 1] + 2;
			RL = Pointer[Tar + 1] - 2;
			if (Left < 0)
				Left += 8;
			if (Right > 7)
				Right -= 8;
			if (RL < 0)
				RL += 8;
			if (LR > 7)
				LR -= 8;
			Swap(&Temp, &Pointer[Tar]);
			if (Magnet[Tar][Left] + Magnet[Tar - 1][LR] == 1) { // ���ʲ� ȸ��
				Solve(Tar - 1, Mirror(Rot), 2);
			}
			if (Magnet[Tar][Right] + Magnet[Tar + 1][RL] == 1) { // �����ʲ� ȸ��
				Solve(Tar + 1, Mirror(Rot), 3);
			}
		}
		else if (Tar == 0) {
			Swap(&Temp, &Pointer[Tar]);
			int Right, RL;
			Right = Pointer[Tar] + 2;
			RL = Pointer[Tar + 1] - 2;
			if (Right > 7)
				Right -= 8;
			if (RL < 0)
				RL += 8;
			Swap(&Temp, &Pointer[Tar]);
			if (Magnet[Tar][Right] + Magnet[Tar + 1][RL] == 1) { // �����ʲ� ȸ��
				Solve(Tar + 1, Mirror(Rot), 3);
			}
		}
		else if (Tar == 3) {
			Swap(&Temp, &Pointer[Tar]);
			int Left, LR;
			Left = Pointer[Tar] - 2;
			LR = Pointer[Tar - 1] + 2;
			if (Left < 0)
				Left += 8;
			if (LR > 7)
				LR -= 8;
			Swap(&Temp, &Pointer[Tar]);
			if (Magnet[Tar][Left] + Magnet[Tar - 1][LR] == 1) { // ���ʲ� ȸ��
				Solve(Tar - 1, Mirror(Rot), 2);
			}
		}
	}
	else if (Strt == 2 && Tar != 0)// �ƴϸ� ���⿡ ���缭 ����
	{
		Swap(&Temp, &Pointer[Tar]);
		int Left, LR;
		Left = Pointer[Tar] - 2;
		LR = Pointer[Tar - 1] + 2;
		if (Left < 0)
			Left += 8;
		if (LR > 7)
			LR -= 8;
		Swap(&Temp, &Pointer[Tar]);
		if (Magnet[Tar][Left] + Magnet[Tar - 1][LR] == 1) { // ���ʲ� ȸ��
			Solve(Tar - 1, Mirror(Rot), 2);
		}
	}
	else if (Strt == 3 && Tar != 3) {
		Swap(&Temp, &Pointer[Tar]);
		int Right, RL;
		Right = Pointer[Tar] + 2;
		RL = Pointer[Tar + 1] - 2;
		if (Right > 7)
			Right -= 8;
		if (RL < 0)
			RL += 8;
		Swap(&Temp, &Pointer[Tar]);
		if (Magnet[Tar][Right] + Magnet[Tar + 1][RL] == 1) { // �����ʲ� ȸ��
			Solve(Tar + 1, Mirror(Rot), 3);
		}
	}
}

void Swap(int *A, int *B)
{
	int Temp;

	Temp = *A;
	*A = *B;
	*B = Temp;
}