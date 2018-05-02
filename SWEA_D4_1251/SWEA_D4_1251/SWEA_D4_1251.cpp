#include <cstdio>
#define MAX 1e15

long long Distance[1000], Result;
long long Map[1000][2];
long long Connected[1000];
int N;

void Solve();
long long Dist(long long X1, long long Y1, long long X2, long long Y2);

int main()
{
	int TC;
	double E;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		Result = 0;
		for (int j = 0; j < N; j++) { // x��ǥ ����
			scanf("%lld", &Map[j][0]);
			Connected[j] = 0;
			Distance[j] = MAX;
		}

		for (int j = 0; j < N; j++) // y��ǥ ����
			scanf("%lld", &Map[j][1]);

		scanf("%lf", &E); // ȯ�� �δ� ���� ����
		Distance[0] = 0;

		Solve();
		printf("#%d %.0lf\n", i, Result*E);
	}

	return 0;
}

void Solve()
{
	for (int i = 0; i < N; i++) {
		long long Temp = MAX;
		int P = i;

		for (int j = 0; j < N; j++) {
			if (!Connected[j] && Distance[j] <= Temp) {// ���� �ȉ�� �Ÿ��� �� ����� ��
				P = j;
				Temp = Distance[j];
			}
		}

		Connected[P] = 1;// �湮�ϰ�
		Result += Temp; // �Ÿ� ���صΰ�

		for (int j = 0; j < N; j++) {
			if (!Connected[j] && (Dist(Map[P][0], Map[P][1], Map[j][0], Map[j][1]) < Distance[j]))// ���� �ȵ� �� �߿� ���±��� ���� �͵� �߿� ������� �Ǵ�
				Distance[j] = Dist(Map[P][0], Map[P][1], Map[j][0], Map[j][1]);
		}
	}
}

long long Dist(long long X1, long long Y1, long long X2, long long Y2)
{
	return ((X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2));
}