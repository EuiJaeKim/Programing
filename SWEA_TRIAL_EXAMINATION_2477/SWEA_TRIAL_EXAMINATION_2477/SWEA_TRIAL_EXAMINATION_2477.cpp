#include <cstdio>

int Client[1000][3] = { 0 }; // 0 ���� �ð� 1 ����â�� ��ȣ 2 ���� â�� ��ȣ
int N[9][2] = { 0 };
int M[9][2] = { 0 };
int ClientCount;
int NC;// ���� â��
int MC;// ���� â��
int GoalN, GoalM;
int Solve();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {

		scanf("%d %d %d %d %d", &NC, &MC, &ClientCount, &GoalN, &GoalM);

		for (int j = 0; j < NC; j++) {
			scanf("%d", &N[j][0]);
			N[j][1] = -1;
		}
		for (int j = 0; j < MC; j++) {
			scanf("%d", &M[j][0]);
			M[j][1] = -1;
		}
		for (int j = 0; j < ClientCount; j++)
			scanf("%d", &Client[j][0]);

		printf("#%d %d\n", i, Solve());
		for (int j = 0; j < ClientCount; j++) {
			Client[j][0] = 0;
			Client[j][1] = 0;
			Client[j][2] = 0;
		}
	}

	return 0;
}

int Solve()
{
	int LastClient = 0; // �ʱⰪ 0
	int CurNC = 0, CurMC = 0, WaitC = 0, IngC = 0, IngCN = 0, WaitCN = 0, k = 0, Result = 0;

	int Waiting[1000];
	int WaitingN[1000];
	for (int i = 0; i < 1000; i++) {
		Waiting[i] = -1;
		WaitingN[i] = -1;
	}


	while (LastClient != ClientCount) {

		/* ���� */
		for (int i = 0; i < NC; i++) {
			if (N[i][1] != -1 && Client[N[i][1]][1] == N[i][0]) { //�մ��� ��ŵ� ���ð��� �ٳ�����
				Client[N[i][1]][1] = i + 1; // ���� â�� ��𿡼� �ϼ̴��� ������
				Waiting[WaitC++] = N[i][1]; //����ٿ��ٰ� �־�
				N[i][1] = -1; // �ڸ� ���� 
			}
		}
		if (Client[ClientCount - 1][0] >= k) {
			for (int i = 0; i < ClientCount; i++) {
				if (Client[i][0] == k)
					WaitingN[WaitCN++] = i; // �մ� ���̴� �޾ƶ�
			}
			k++;
		}

		if (CurNC < ClientCount && IngCN < WaitCN) {// ���� â���� �� �մ��� ��ü �մ� ������ ������ ����
			for (int i = 0; i < NC; i++) {
				if (N[i][1] == -1 && IngCN < WaitCN) { // â���� ���ְ� ���� ���ƽ�
					N[i][1] = WaitingN[IngCN++];
					CurNC++;
				}
			}
		}

		for (int i = 0; i < NC; i++) {
			if (N[i][1] != -1 && Client[N[i][1]][1] < N[i][0]) {// â���� �մ��� ��ð� �׼մ��� �����
				Client[N[i][1]][1]++; // �մ� ��� �ð�+1
			}
		}
		/* ���� */
		/* ���� */
		for (int i = 0; i < MC; i++) {
			if (M[i][1] != -1 && Client[M[i][1]][2] == M[i][0]) { //�մ��� ��ŵ� ���ð��� �ٳ�����
				Client[M[i][1]][2] = i + 1; // ���� â�� ��𿡼� �ϼ̴��� ������
				M[i][1] = -1; // �ڸ� ���� 
				LastClient++;
			}
		}
		if (IngC < WaitC) // �մ� ��ٸ��� �մԹ޾ƶ�
			for (int i = 0; i < MC; i++) {
				if (M[i][1] == -1 && IngC < WaitC) {// â���� ���ְ� ���� ������̾�
					M[i][1] = Waiting[IngC++];// ������� �մ� ����
					CurMC++;
				}
			}
		for (int i = 0; i < MC; i++) {
			if (M[i][1] != -1 && Client[M[i][1]][2] < M[i][0]) // â���� �մ��� ��ð� �׼մ��� �����
				Client[M[i][1]][2]++; // �մ� ���� �ð�+1
		}
		/* ���� */
	}

	for (int i = 0; i < ClientCount; i++) {
		if (Client[i][1] == GoalN && Client[i][2] == GoalM)
			Result += i + 1;
	}

	if (Result == 0)
		return -1;
	else
		return Result;
}