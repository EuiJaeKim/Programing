#include <iostream>
#include <vector>

using namespace std;

/*
[�Է�]

ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.

�� �׽�Ʈ ���̽� ���� ù �ٿ��� �ڿ��� N(2 �� N �� 1,000,000)�� �־�����,

��° �ٿ��� �� ���� �ŸŰ��� ��Ÿ���� N���� �ڿ������� �������� ���еǾ� ������� �־�����.

�� ���� �ŸŰ��� 10,000�����̴�.


[���]

�� �׽�Ʈ ���̽����� ��#x��(x�� �׽�Ʈ���̽� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�)�� ����ϰ�, �ִ� ������ ����Ѵ�.
*/

int Max;
int MaxNum;
int Size;
vector<int> Map;
long long Solve();
int MaxChange();

int main()
{
	int TC, Input;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Max = MaxNum = 0;
		Map.clear();
		cin >> Size;

		for (int i = 0; i < Size; i++) {
			cin >> Input;
			if (Input >= Max) {
				Max = Input;
				MaxNum = i;
			}
			Map.push_back(Input);
		}
		printf("#%d %lld\n", i, Solve());
	}
	return 0;
}

long long Solve()
{
	long long Ret = 0;
	int Next, i = 0;
	do {
		while (i < MaxNum) {
			Ret += Max - Map[i++];
		}
		Next = MaxChange();
		i = MaxNum + 1;
		MaxNum = Next;
	} while (i < Size);
	return Ret;
}

int MaxChange()
{
	int NextMaxValue, NextMaxNum;
	NextMaxValue = 0;
	NextMaxNum = MaxNum;
	for (int i = 1; MaxNum + i < Map.size(); i++) {
		if (Map[MaxNum + i] >= NextMaxValue) {
			NextMaxValue = Map[MaxNum + i];
			NextMaxNum = MaxNum + i;
		}
	}
	Max = NextMaxValue;
	return NextMaxNum;
}