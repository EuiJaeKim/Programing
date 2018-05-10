#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �ﰢ���� ũ�� n(2 <= n <= 100)�� �־�����, �� �� n�ٿ��� �� 1��~n���� ���ڷ� �ﰢ�� �� �����ٿ� �ִ� ���ڰ� ���ʺ��� �־����ϴ�. �� ���ڴ� 1 �̻� 100000 ������ �ڿ����Դϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� �ִ� ����� ���� ���� ����մϴ�.
*/
int Map[100][100];
int Visit[100][100];
int N;
int Solve(int X, int Y);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> Map[j][k];
				Visit[j][k] = 0;
			}
		}
		cout << Solve(0, 0) << endl;
	}
	return 0;
}

int Solve(int X, int Y)
{
	if (X == N-1)
		return Map[X][Y];


	if (Visit[X][Y] != 0)
		return Visit[X][Y];

	int A = Solve(X + 1, Y);
	int B = Solve(X + 1, Y + 1);

	if (A > B)
		return Visit[X][Y] = A + Map[X][Y];
	else
		return Visit[X][Y] = B + Map[X][Y];

}

/*
 �Ʒ��� �ڵ忡�� Sum�� �ִ밪�� ���ϴµ� �ƹ� ��� ����( �ܼ� �� ���� ) ���� �̹Ƿ� ���� �� �ְ�,
 X�� ���� ����( base case)�� �迭�� ������ �־ ���� �����ϴ°� ������ ������. �ϳ��� �� �����ؼ� �� ��.
 �׸��� ���������� �������� ���� ���� �����ؼ� ���ϴ°� ���ٴ� �Ʒ����� ���� �ö�� �� ���� �����ؼ� ���ϴ°� �� ����.
# �׷��� ���� �����س����� �� ����ȭ�� �ڵ带 ¥��..
 1. ��Ž 2. �߰� ������ 3. ����ȭ ���� ���ϴµ� ����ϴ� ������ �ƴϸ� �Ű����� ���ֱ�

int Solve(int X, int Y, int Sum)
{
if (X == N)
return Sum;


if (Visit[X][Y] > Map[X][Y] + Sum)
return 0;
Visit[X][Y] = Map[X][Y] + Sum;

int A = Solve(X + 1, Y, Visit[X][Y]);
int B = Solve(X + 1, Y + 1, Visit[X][Y]);

if (A > B)
return A;
else
return B;

}
*/