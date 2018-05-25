#include <iostream>

using namespace std;
int Map[3]; /* (11 �� D �� 14) */ /* (0 �� H �� 23) */ /* (0 �� M �� 59) */

int Solve();

int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> Map[0] >> Map[1] >> Map[2];
		printf("#%d %d\n", i, Solve());
	}
	return 0;
}

int Solve()
{
	int Res[3] = { 11,11,11 };
	int Ret;
	for (int i = 0; i < 3; i++)
		Map[i] -= Res[i];
	Ret = ((Map[0] * 24) + Map[1]) * 60 + Map[2];

	return (Ret < 0 ? -1 : Ret);
}