#include <iostream>

using namespace std;

/*
�Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ �� N (1��N��20000)�� �־����ϴ�. �� ���� �ٿ��� N���� ������ ���ʺ��� �� ������ ���̰� ������� �־����ϴ�. ���̴� ��� 10,000 ������ ���� �ƴ� �����Դϴ�.

���
�� �׽�Ʈ ���̽��� ���� �ϳ��� �� �ٿ� ����մϴ�. �� ������ �־��� ��Ÿ������ �߶� �� �ִ� �ִ� ���簢���� ũ�⸦ ��Ÿ���� �մϴ�.
*/
int Arr[20000] = { 0, }; // ������ �� N (1��N��20000) , ���̴� ��� 10,000 ������ ���� �ƴ� ����
int Length; // ������ �� N 

int Solve(int Left, int Right);\
int max(int a, int b) { if (a > b) return a; else return b; }
int min(int a, int b) { if (a < b) return a; else return b; }
int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> Length;
		for (int j = 0; j < Length; j++)
			cin >> Arr[j];
		cout << Solve(0, Length - 1) << endl;\
	}

	return 0;
}

int Solve(int Left, int Right)
{
	int Max, CenterMax;
	int Center = (Left + Right) / 2; // �߰� ã��

	if (Left == Right)
		return Arr[Left];

	int i = Center;
	int j = Center + 1;
	int Min = min(Arr[i], Arr[j]);
	CenterMax = Min * 2;
	Max = max(Solve(Left, i), Solve(j, Right)); // ���� ������ �� ū��

	while (i > Left || j < Right) {
		if (j < Right && ( i == Left || Arr[i - 1] < Arr[j + 1])) // j > ������ ���� Right ���� ������ �۾ƾ��ϰ� �� ���߿� i�� ���� ���� �����߰ų�? �����ʲ��� �߰��ؾ��ϴ� ��Ȳ�̸� �߰��غ�.
			Min = min(Min, Arr[++j]);
		else // �� ������ Ʋ���� ���ʲ��� �غ�����.
			Min = min(Min, Arr[--i]);
		CenterMax = max(CenterMax, (j - i + 1)* Min);
	}
	return max(Max, CenterMax);
}