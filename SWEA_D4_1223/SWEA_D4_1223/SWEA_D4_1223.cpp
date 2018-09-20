#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
[�Է�]

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �׽�Ʈ ���̽��� ���̰� �־�����. �� ���� �ٿ� �ٷ� �׽�Ʈ ���̽��� �־�����.

�� 10���� �׽�Ʈ ���̽��� �־�����.

[���]

#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� ���� ����Ѵ�.
*/

vector<char> Str;

int Priority(char Input);
void Init(int Length);
int Calculation();

int main()
{
	int Length;

	for (int i = 1; i <= 10; i++) {
		cin >> Length;
		Init(Length);
		printf("#%d %d\n", i, Calculation());
	}

	return 0;
}

void Init(int Length)
{
	char Input;
	stack<char> Data;
	stack<char> Temp;
	Str.clear();
	Str.resize(Length);

	for (int j = 0; j < Length; j++) {
		cin >> Input;
		if (Input >= '0' && Input <= '9')
			Data.push(Input);
		else {
			while (!Temp.empty()) {
				if (Priority(Temp.top()) >= Priority(Input)) {
					Data.push(Temp.top());
					Temp.pop();
				}
				else
					break;
			}
			Temp.push(Input);
		}
	}
	while (!Temp.empty()) {
		Data.push(Temp.top());
		Temp.pop();
	}
	for (int i = Length - 1; i >= 0; i--) {
		Str[i] = Data.top();
		Data.pop();
	}
}

int Priority(char Input)
{
	if (Input == '+')
		return 0;
	else if (Input == '*')
		return 1;
}

int Calculation()
{
	int Result = 0;
	stack<int> Value;

	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] >= '0' && Str[i] <= '9')
			Value.push(Str[i] - '0');
		else {
			Result = Value.top();
			Value.pop();
			if (Str[i] == '+')
				Result += Value.top();
			else if (Str[i] == '*')
				Result *= Value.top();
			Value.pop();
			Value.push(Result);
		}
	}
	return Value.top();
}