#include <iostream>

using namespace std;

/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� c ( 1 <= c <= 50 ) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100). ���� �ٿ��� n ���� ������ A �� ���ҵ���, �� ���� �ٿ��� m ���� ������ B �� ���ҵ��� �־����ϴ�. ��� ���ҵ��� 32��Ʈ ��ȣ �ִ� ������ ������ �� �ֽ��ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ�, JLIS �� ���̸� ����մϴ�.
*/

int N, M; // A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100)
int MAX;
int Cache[100][100];
int A[100] = { 0, }, B[100] = { 0, };

int Solve(int IsArr, int Count, int min);
int Max(int X, int Y) { if (X > Y) return X; else return Y; }

int main()
{
	int TC;
	int input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M;
		MAX = 0;
		for (int j = 0; j < N; j++) 
			cin >> A[j];
		for (int j = 0; j < M; j++)
			cin >> B[j];
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				Cache[j][k] = 0;


		cout << MAX << endl;
	}
	return 0;
}

int Solve(int AX, int BX)
{
	/* �� ��Ǯ���� ���̵� �� �ε� �� ��Ǯ��.. �ϴ�.. Ǯ�̸� ���Ҵ�..
	���ڿ� 2�� ��ġ�°Ŵϱ� dvide �ϴ� ��������.. ����..�غ���.. �ϴ�.. ������ ���� �����Ұ���
	*/

	

	//if (IsArr == 0) {
	//	for (int i = Count + 1; i < N; i++) {
	//		if (A[i] > A[Count]) { // �����ϰ�
	//			if (CacheA[i] == 0) // ��� �ߴ� ���� �ƴϸ�
	//				CacheA[Count] = Max(CacheA[Count], Solve(0, i, min) + 1);
	//			else // ��� �ߴ� ���̸�
	//				CacheA[Count] = Max(CacheA[Count], CacheA[i] + 1);
	//		}
	//	}
	//	for (int i = min + 1; i < M; i++) {
	//		if (B[i] > A[Count]) { // �����ϰ�
	//			if (CacheB[i] == 0) // ��� �ߴ� ���� �ƴϸ�
	//				CacheA[Count] = Max(CacheA[Count], Solve(1, i, Count) + 1);
	//			else // ��� �ߴ� ���̸�
	//				CacheA[Count] = Max(CacheA[Count], CacheB[i] + 1);
	//		}
	//	}

	//	if (CacheA[Count] == 0)
	//		CacheA[Count] = 1;
	//	MAX = Max(MAX, CacheA[Count]);
	//	return CacheA[Count];
	//}
}
