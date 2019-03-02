#include <iostream>

#define Max 50
using namespace std;

int N, M;
int Result;
int Map[Max][Max]; // ��ĭ 0, �� 1 , û�ҵ� ���� 2
int Robot[3] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Init();
void Solve();
int SearchDirReturn(int i);

int main()
{
	Init();
	Solve();
	cout << Result;
	return 0;
}

void Init()
{
	Result = 1;
	cin >> N >> M;
	for (int i = 0; i < 3; i++)
		cin >> Robot[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
}

void Solve()
{
	int Dir;
	bool Cleaned;

	while (1) {
		Map[Robot[0]][Robot[1]] = 2; // ���� ��ġ�� û���Ѵ�.
		Cleaned = false;
		for (int i = 0; i < 4; i++) {
			Dir = SearchDirReturn(1); // ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
			Robot[2] = Dir;
			if (Map[Robot[0] + dx[Dir]][Robot[1] + dy[Dir]] == 0) { // ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
				Robot[0] += dx[Dir];
				Robot[1] += dy[Dir];
				Cleaned = true;
				Result++;
				break;
			}
		}

		if (!Cleaned) {
			if (Map[Robot[0] - dx[Robot[2]]][Robot[1] - dy[Robot[2]]] == 1)
				break; // �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����
			else { // �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
				Robot[0] -= dx[Robot[2]];
				Robot[1] -= dy[Robot[2]];
			}
		}

	}
}

int SearchDirReturn(int i)
{

	if (Robot[2] - i > -1)
		return Robot[2] - i;
	else
		return 4 + (Robot[2] - i);
}
