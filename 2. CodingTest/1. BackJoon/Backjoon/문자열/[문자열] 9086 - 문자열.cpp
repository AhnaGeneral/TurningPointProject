#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int c;
	cin >> c;

	while (c--)
	{
		string str;
		cin >> str;

		cout << str[0] << str[str.size() - 1];
	}

	return 0;
}
