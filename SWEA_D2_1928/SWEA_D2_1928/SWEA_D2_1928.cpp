#include <iostream>
#include <string>

using namespace std;

/*

[�������]
���ڿ��� ���̴� �׻� 4�� ����� �־�����.
�׸��� ���ڿ��� ���̴� 100000�� ���� �ʴ´�.

[�Է�]
�Է��� ù �ٿ� �� �׽�Ʈ ���̽��� ���� T�� �´�.
���� �ٺ��� �� �׽�Ʈ ���̽��� �־�����.
�׽�Ʈ ���̽��� Encoding �� ���·� �־����� ���ڿ��̴�.

[���]
�׽�Ʈ ���̽� t�� ���� ����� ��#t���� ���, �� ĭ ���, ������ ����Ѵ�.
(t�� �׽�Ʈ ���̽��� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�.)

*/

string Input;

void Sovle();

int main()
{
	int TC;


	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Input.clear();
		cin >> Input;
		printf("#%d ",i);
		Sovle();
		cout << endl;
	}


	return 0;
}

void Sovle()
{
	int arr[24] = { 0, };
	int* InputInt;
	int Length = Input.size();

	InputInt = new int[Length];
	/* 1. ���ڷ� �ٲٰ� */
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i] >= 'A' && Input[i] <= 'Z')
			InputInt[i] = Input[i] - 'A';
		else if (Input[i] >= 'a' && Input[i] <= 'z')
			InputInt[i] = Input[i] - 'a' + 26;
		else if (Input[i] >= '0' && Input[i] <= '9')
			InputInt[i] = Input[i] - '0' + 52;
		else if (Input[i] == '+')
			InputInt[i] = 62;
		else if (Input[i] == '/')
			InputInt[i] = 63;
	}
	/* 2. 4���� �о 24���� �迭 arr�� �����ϰ� 8��Ʈ�� �о ��� */
	int Cur = 0;
	int BitCur;

	while (Cur < Length) {
		BitCur = 0;
		for (int i = 0; i < 4; i++) {
			if (InputInt[Cur + i] >= 32) {
				InputInt[Cur + i] -= 32;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 16) {
				InputInt[Cur + i] -= 16;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 8) {
				InputInt[Cur + i] -= 8;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 4) {
				InputInt[Cur + i] -= 4;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 2) {
				InputInt[Cur + i] -= 2;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 1) {
				InputInt[Cur + i] -= 1;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
		}

		/* ����ȭ */
		char Result;
		int i = 0, Temp;
		while (i < 24) {
			Result = 0;
			Temp = 128;
			for (int j = 0; j < 8; j++) {
				if (arr[i + j] == 1)
					Result += Temp;
				Temp /= 2;
			}
			i += 8;
			cout << Result;
		}
		Cur += 4;
	}
}