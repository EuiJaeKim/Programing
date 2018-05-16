#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
�Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��20)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ������� ������ �ҵ��� ������ ���� ��Ÿ���� �� ���� ���ڿ��� �����Ǿ� �ֽ��ϴ�. �� ���ڿ��� ���ʺ��� ������ ������� �� ������� ������ ��Ÿ���ϴ�.

M�� �ش��ϴ� ����� ����, F�� �ش��ϴ� ����� �������� ��Ÿ���ϴ�. ����� ���� ���� ���� ��� 1 �̻� 200,000 ������ �����̸�, ����� ���� �׻� ���� �� �����Դϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ��� ������� ������ �ϴ� ���� �� ���̳� �ִ��� ����մϴ�.
*/

/*
http://devidea.tistory.com/entry/%EB%B6%84%ED%95%A0%EC%A0%95%EB%B3%B5-%EC%B9%B4%EB%9D%BC%EC%B8%A0%EB%B0%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
https://en.wikipedia.org/wiki/Karatsuba_algorithm
http://jaimemin.tistory.com/311
ī������ �˰���(Karatsuba algorithm)���� �ذ� �����ϴٰ���.
���������� ��ǥ���� �������ϴ� �غ��ô�
*/

/*

������ ������ if�� ������ �ּұ��� �̰� left right�� ������ left�� ������ Start�� (End - Start) / 2�� ���ؾ��Ѵ�.
right�� ������ ���� Start�� (End - Start) / 2�� �������� �����ؾ��Ѵ�.
��������

if ((End - Start) / 2 >= HyperSenior.size()) {
LeftSum = Solve(Start, Start + (End - Start) / 2);
RightSum = Solve(Start+((End - Start) / 2), End);
}
*/

string HyperSenior;
string Fans;

int Solve(int Start, int End);
int JongManSolve();
int SolveT();
bool Check(int Start);

int main()
{
	int TC;
	char Input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		HyperSenior.resize(200000);
		Fans.resize(200000);
		cin >> HyperSenior;
		cin >> Fans;

		cout << Solve(0, Fans.size()) << endl;
		cout << JongManSolve() << endl;
		cout << SolveT() << endl;
		HyperSenior.clear();
		Fans.clear();
	}

	return 0;
}

int JongManSolve()
{
	int N = HyperSenior.size() + Fans.size() - 1;
	int Compare = 0;
	vector<int> A(HyperSenior.size()), B(N, 0);
	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M') {
			A[i] = 1;
		}

	}

	int Cur = 0;
	for (int i = 0; i < Fans.size(); i++) {
		if (Fans[i] == 'M')
		{
			for (int j = A.size() - 1; j >= 0; j--) {
				B[Cur + (A.size() - 1 - j)] += A[j];
			}
		}
		Cur++;
	}

	int Ret = 0;
	for (int i = HyperSenior.size() - 1; i < Fans.size(); i++)
		if (B[i] == 0)
			Ret++;
	A.clear();
	B.clear();
	return Ret;
}

int SolveT()
{
	/*
	1. �迭 A�� HyperSenior�� M�� ������ŭ�� ���̸� �������ְ�, �� ������ ���� HyperSenior�迭���� M�� ��ġ.
	2. �迭 Fans�� �������� M�� ���ö����� ��ġ. M�� ������ŭ��.
	*/
	vector<int> A;
	bool CountUp;
	int Count=0;

	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M')
			A.push_back(i);
	}
	if (A.size() != 0) {
		for (int i = A[0]; i + HyperSenior.size() - 1 - A[0] < Fans.size(); i++) {
			if (Fans[i] == 'F') {
				CountUp = true;
				for (int j = 1; j < A.size(); j++) {
					if (Fans[i + (A[j] - A[0])] == 'M') {
						CountUp = false;
						break;
					}
				}
				if (CountUp)
					Count++;
			}
		}
	}
	else {
		Count = Fans.size() - HyperSenior.size() + 1;
	}
	A.clear();

	return Count;
}

int Solve(int Start, int End)
{
	int LeftSum, RightSum;
	LeftSum = RightSum = 0;

	if ((End - Start) / 2 >= HyperSenior.size()) {
		LeftSum = Solve(Start, Start + (End - Start) / 2);
		RightSum = Solve(Start + ((End - Start) / 2), End);
	}

	int Count = 0;
	for (int StartCur = Start + ((End - Start) / 2) - 1; StartCur >= Start; StartCur--) {
		if (StartCur + HyperSenior.size() <= End && StartCur + HyperSenior.size() > Start + (End - Start) / 2) {
			if (Check(StartCur)) {
				Count++;
			}
		}
	}
	return Count + LeftSum + RightSum;
}

bool Check(int Start)
{
	bool Res = true;
	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M' && Fans[Start + i] == 'M') {
			return Res = false;
		}
	}
	return Res;
}