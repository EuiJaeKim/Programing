#include <cstdio>

int P, Q, R, S, W;// A�� : 1���ʹ� P��, B�� : �⺻ ����� Q�� ���� ��뷮�� R���� �ʰ����� ���� 1���ʹ� S�� ����ϴ� ������ ���� W����

int Solve();

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d %d %d", &P, &Q, &R, &S, &W);
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

int Solve()
{// A�� : 1���ʹ� P��, B�� : �⺻ ����� Q�� ���� ��뷮�� R���� �ʰ����� ���� 1���ʹ� S�� ����ϴ� ������ ���� W����
	int Temp;
	if (R >= W)
		Temp = Q;
	else
		Temp = Q + (W - R)*S;

	if (P*W > Temp)
		return Temp;
	else
		return P * W;
}