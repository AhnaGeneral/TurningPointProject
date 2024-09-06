#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			cout << " ";
		}

		// 1 , 3 , 5 , 7 , 9 
		int index = 1 + (2 * (i - 1)); 
		for (int j = 0; j < index; ++j)
		{
			if (i == n)
			{
				cout << "*";
			}
			else
			{
				if (j == 0 || j == index - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
		}

		cout << "\n";
	}
}