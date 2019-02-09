#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int Map[100][100];
bool Visit[100][100];
int N;

typedef struct Body {
	int X;
	int Y;
}Body;

vector<Body> Snake;

void Init();
int Solve();
bool Move(int Dir);

int main()
{
	Init();
	printf("%d", Solve());
	return 0;
}

void Init()
{
	int K, X, Y;
	Body Temp;

	memset(Map, 0, sizeof(Map));
	memset(Visit, 0, sizeof(Visit));
	Temp.X = 0;
	Temp.Y = 0;
	Visit[0][0] = true;

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> X >> Y;
		Map[X - 1][Y - 1] = 1;
	}

	Snake.push_back(Temp);
}

int Solve()
{
	int L, Time, X, Dir; // Dir -> 0 ������ 1 �Ʒ��� 2 ���� 3 ����
	char C;

	Time = Dir = 0;
	cin >> L;

	while (L > 0) {
		cin >> X >> C;

		while (Time < X ) {
			
			if (Time != X) {
				if (!Move(Dir))
					return Time+1;
			}
			Time++;
		}
		if (C == 'D')
			Dir++;
		else
			Dir--;

		if (Dir == -1)
			Dir = 3;
		else if (Dir == 4)
			Dir = 0;

		L--;
	}

	while (1) {
		
		if (!Move(Dir))
			return Time+1;
		Time++;
	}
}

bool Move(int Dir)
{
	int HeadX, HeadY;
	vector<Body>::iterator iter;

	HeadX = Snake[0].X;
	HeadY = Snake[0].Y;

	switch (Dir)
	{
	case 0:
		if (HeadY + 1 >= N) // 1. Map�� �Ѿ�� ��
			return false;
		if (!Visit[HeadX][HeadY + 1] && Map[HeadX][HeadY + 1] == 0) { // �湮 ���� �ʾҰ� ����� ���ٸ�
			if (Snake.size() == 1) { // 2 - 1. Map�� �Ѿ�� �����鼭 ��������� ������ �� �� �� �ְ�, ����� ����, �� ���̴� 1 �϶�
				Snake[0].Y++;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else { // 2 - 2. Map�� �Ѿ�� �����鼭 ��������� ������ �� �� �� �ְ�, ����� ����, �� ���̴� 1 �̻� �϶�
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX;
				Temp.Y = HeadY + 1;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX][HeadY + 1]) { // �湮 �ߴٸ�
			return false; // 3. �湮 �ߴ� ��(���� ���� �ִ� ��)�̸� ��
		}
		else if(!Visit[HeadX][HeadY + 1] && Map[HeadX][HeadY + 1] == 1) { // �湮 ���� �ʾҰ� ����� �ִٸ�
			Map[HeadX][HeadY + 1] = 0; // 4. Map�� �Ѿ�� �����鼭 ��������� ������ �� �� �� �ְ�, ����� ���� ��
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX;
			Temp.Y = HeadY + 1;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 1:
		if (HeadX + 1 >= N)
			return false;
		if (!Visit[HeadX + 1][HeadY] && Map[HeadX + 1][HeadY] == 0) { // �湮 ���� �ʾҰ� ����� ���ٸ�
			if (Snake.size() == 1) {
				Snake[0].X++;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX + 1;
				Temp.Y = HeadY;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX + 1][HeadY]) { // �湮 �ߴٸ�
			return false;
		}
		else if (!Visit[HeadX + 1][HeadY] && Map[HeadX + 1][HeadY] == 1) { // �湮 ���� �ʾҰ� ����� �ִٸ�
			Map[HeadX + 1][HeadY] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX + 1;
			Temp.Y = HeadY;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 2:
		if (HeadY - 1 < 0)
			return false;
		if (!Visit[HeadX][HeadY - 1] && Map[HeadX][HeadY - 1] == 0) { // �湮 ���� �ʾҰ� ����� ���ٸ�
			if (Snake.size() == 1) {
				Snake[0].Y--;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX;
				Temp.Y = HeadY - 1;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX][HeadY - 1]) { // �湮 �ߴٸ�
			return false;
		}
		else if (!Visit[HeadX][HeadY - 1] && Map[HeadX][HeadY - 1] == 1) { // �湮 ���� �ʾҰ� ����� �ִٸ�
			Map[HeadX][HeadY - 1] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX;
			Temp.Y = HeadY - 1;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 3:
		if (HeadX - 1 < 0)
			return false;
		if (!Visit[HeadX - 1][HeadY] && Map[HeadX - 1][HeadY] == 0) { // �湮 ���� �ʾҰ� ����� ���ٸ�
			if (Snake.size() == 1) {
				Snake[0].X--;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX - 1;
				Temp.Y = HeadY;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX - 1][HeadY]) { // �湮 �ߴٸ�
			return false;
		}
		else if (!Visit[HeadX - 1][HeadY] && Map[HeadX - 1][HeadY] == 1) { // �湮 ���� �ʾҰ� ����� �ִٸ�
			Map[HeadX - 1][HeadY] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX - 1;
			Temp.Y = HeadY;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	}
}