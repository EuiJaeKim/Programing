#include <cstdio>
int D, W, K;

int Map[13][20];

int Check();
int Solve();
int Medicine(int Count, int Layer);

int main()
{
	int T;
	int Result;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &D, &W, &K);

		for (int j = 0; j < D; j++) {
			for (int k = 0; k < W; k++) {
				scanf("%d", &Map[j][k]);
			}
		}
		printf("#%d %d\n", i, Solve());
	}
	return 0;
}

int Solve()
{
	if (Check())// �ȹٲ㵵 ����Դϴ�
		return 0;

	for (int i = K - 1; i > 0; i--) { // 1�ٺ��� �ٲ㺼���� �ִ� D���� ���� �ٲܲ��� �ٵ� ? �׷��ʿ䰡 ���� �ִ� K���� �ٲٸ� �Ǵϱ� 
		for (int j = 0; (j + i) <= D; j++) { // j�� ���� Layer
			if (Medicine(i, j))
				return i;
		}
	}
	return K;
}

int Medicine(int Count, int Layer)
{
	int Temp[20];
	int Tem;

	if (Count > 1) { // 2�̻��̸�
		for (int j = 0; j < W; j++) {// �ϴ� ���� A������ �ٲ�
			Temp[j] = Map[Layer][j];
			Map[Layer][j] = 0;
		}

		for (int j = Layer + 1; j + Count - 1 <= D; j++) {
			Tem = Medicine(Count - 1, j); //������~
			if (Tem)// �ؿ��� �����߾�!?
				return 1;
		}
		// �����ؽ�.. B������ �ٽ��غ��ھ�..
		for (int j = 0; j < W; j++)
			Map[Layer][j] = 1;

		for (int j = Layer + 1; j + Count - 1 <= D; j++) {
			Tem = Medicine(Count - 1, j); //������~
			if (Tem)// �ؿ��� �����߾�!?
				return 1;
		}

		//����ƴѰ���.. �ٸ������� ����..
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = Temp[j];
		}
		return 0;
	}
	else { // count = 1
		for (int j = 0; j < W; j++) { // ���� A��
			Temp[j] = Map[Layer][j];
			Map[Layer][j] = 0;
		}

		if (Check())// �˻��ߴµ� ����� ��
			return 1;

		// �ƴϸ� B�� �־�
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = 1;
		}

		if (Check()) // �˻���
			return 1;

		for (int j = 0; j < W; j++) {
			Map[Layer][j] = Temp[j];
		}

		return 0;
	}
}

int Check()
{
	int Temp, TempCount, Flag;
	Flag = 0;

	for (int i = 0; i < W; i++) {
		Temp = Map[0][i];
		TempCount = 1;
		for (int j = 1; j < D; j++) {

			if (Temp == Map[j][i])
				TempCount++;
			else {
				Temp = Map[j][i];
				TempCount = 1;
			}

			if (TempCount == K) {
				Flag++;
				break;
			}
		}
	}
	if (Flag == W)
		return 1;
	else
		return 0;
}