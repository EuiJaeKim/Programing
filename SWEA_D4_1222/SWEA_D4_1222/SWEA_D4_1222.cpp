#include <iostream>

using namespace std;

/*
[�Է�]

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���ڿ� ������ ���̰� �־�����. �� ���� �ٿ� ���ڿ� ������ �־�����.

�� 10���� �׽�Ʈ ���̽��� �־�����.

[���]

#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� ���� ����Ѵ�.
*/

int main()
{
	int Length;
	int Res;
	char Input;

	for (int i = 1; i <= 10; i++) {
		cin >> Length;
		Res = 0;
		for (int j = 0; j < Length; j++) {
			cin >> Input;
			if (Input != '+')
				Res += Input - '0';
		}
		printf("#%d %d\n",i,Res);

	}

	return 0;
}