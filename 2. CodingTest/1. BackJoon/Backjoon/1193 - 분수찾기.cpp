#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int X;
	cin >> X;
	//  1    2    6    7   15   16 
	//  3    5    8   14   17
	//  4    9   13  18
	// 10  12   19
	// 11  20  
	// 21

	int start = 0;
	for (int i = 1; i <= X; i++)
	{
		start += i;
		if (X == start)
		{
			if (i % 2 == 0)//Â¦¼ö
			{
				cout << i << "/1";
				return 0;
			}
			else //È¦¼ö
			{
				cout << "1/" << i;
				return 0;
			}
		}
	}
	for (int i = 1; i <= X; i++)
	{
		int index = 0;
		if (X < ((i * (i + 1)) / 2))
		{
			int mi;
			index = ((i * (i + 1)) / 2);
			mi = index - X;
			if (i % 2 == 0) // Â¦¼ö 
			{
				cout << i - mi << "/" << 1 + mi;
			}
			else //È¦¼ö
			{
				cout << 1 + mi << "/" << i - mi;
			}
			//break;
			return 0;
		}
		//else if (X == (i * (i + 1)) / 2)
		//{
		//	cout << "1/1";
		//	return 0;
		//}

	}
}
    
