#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << " ";
		}

		for (int j = 1 + (2 * (n - i - 1)); j > 0; --j)
		{
			cout << "*";
		}
		if(i!=n)
		cout << "\n";
	}


	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 2 - i; ++j)
		{
			cout << " ";
		}

		for (int j = 0; j < 1 + (2 * (i + 1)); ++j)
		{
			cout << "*";
		}
		cout << "\n";
	}
}