#include <iostream>

using namespace std;

/*
[�������]

�� ���뿡�� ����� ���μ��� �ٸ� ���븦 ���������� �����Ͽ� �̾����� ���� ����.

[�Է�]

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �׽�Ʈ ���̽��� ��ȣ�� �־�����, �ٷ� ���� �ٿ� �׽�Ʈ ���̽��� �־�����.

�� 10���� �׽�Ʈ ���̽��� �־�����.

[���]

#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� �����ϰ� �Ǵ� ������� x��ǥ�� ����Ѵ�.
*/

#define Max 100
#define MAX(A,B) A > B ? A : B

int Map[Max][Max];
int MaxVal;
int Res;

void Move(int X, int Y, int Start, int Count);

int main()
{
	int Count;
	for (int i = 1; i <= 10; i++) {
		MaxVal = 987654321;
		cin >> Count;
		for (int j = 0; j < Max; j++)
			for (int k = 0; k < Max; k++)
				cin >> Map[j][k];

		for (int j = 0; j < Max; j++) {
			if (Map[0][j] == 1)
				Move(0, j, j, 1);
		}
		printf("#%d %d\n", Count, Res);
	}

	return 0;
}

void Move(int X, int Y, int Start, int Count)
{
	/* Base Case */
	if (X == Max) {
		if (MaxVal == Count)
			Res = Start;
		else if (MaxVal > Count) {
			MaxVal = Count;
			Res = Start;
		}
		return;
	}
	if (MaxVal <= Count)
		return;

	if (Y - 1 >= 0 && Map[X][Y - 1] == 1) {
		while (Y >= 0 && Map[X][Y] == 1) {
			Y--;
			Count++;
		}
		Y++;
		Count--;
	}
	else if (Y + 1 < Max && Map[X][Y + 1] == 1) {
		while (Y < Max && Map[X][Y] == 1) {
			Y++;
			Count++;
		}
		Y--;
		Count--;
	}

	Move(X + 1, Y, Start, Count + 1);

}