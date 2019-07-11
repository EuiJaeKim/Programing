#include <iostream>

using namespace std;
typedef struct Node
{
	char Taller[501] = { 0, };
	bool Flag = false;
}Node;

int N; // �л����� �� (2 �� N �� 500)
int M; // �� �л��� Ű�� ���� Ƚ�� (0 �� M �� N*(N-1)/2)

void Input(Node Map[],int Small, int Tall)
{
	Map[Tall].Taller[Small] = 1;
}
int Search(Node Map[]);
void Run(Node Map[], int Count);

int main()
{
	int TC, Small, Tall;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Node Map[501];
		cin >> N >> M;
		for (int j = 0; j < M; j++) {
			cin >> Small >> Tall;
			Input(Map,Small, Tall);
		}
		printf("#%d %d\n",i, Search(Map));
		//cout << Search(Map) << endl;
	}
	return 0;
}

int Search(Node Map[])
{
	int Count=0;
	bool Flag;

	for (int i = 1; i <= N; i++) {
		if (!Map[i].Flag)
			Run(Map,i);
	}

	for (int i = 1; i <= N; i++) {
		Flag = true;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if (Map[i].Taller[j] == 0) {
				if (Map[j].Taller[i] == 0) {
					Flag = false;
					break;
				}
			}
		}
		if (Flag)
			Count++;
	}

	return Count;
}

/* �ڽź��� ���� �ְ� ���������� ���ͼ� ���� �����ְ� ������ Flag�� true �ٲٰ� �ڽź��� ū�ַ� ��� �Ǹ鼭 or �������� ��� ����. */
void Run(Node Map[],int Count)
{
	for (int i = 0; i < N; i++) {
		if (Map[Count].Taller[i] == 1) {
			if (!Map[i].Flag)
				Run(Map,i);
			for (int j = 0; j < N; j++) {
				Map[Count].Taller[j] |= Map[i].Taller[j];
			}
		}
	}
	Map[Count].Flag = true;
}