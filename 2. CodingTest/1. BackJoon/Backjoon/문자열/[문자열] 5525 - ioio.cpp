#include<iostream>
#include<vector>
using namespace std;

char chr[1'000'000];
// ---> 1 <= n <= 1,000,000
// ---> 2n+1 <= m <= 1,000,000
// ---> S는 i와 o로만 이루어져 있다.

int main()
{
	int n, m;

	cin >> n >> m; 
	
	for (int i = 0; i < m; ++i)
	{
		cin >> chr[i];
	}

	// ----------------------------- //
	vector<char> vec;
	for (int i = 0; i < n; ++i)
	{
		vec.push_back('I'); 
		vec.push_back('O');
	}
	vec.push_back('I');
	// ----------------------------- //

	int index = 0; 
	bool trueorFalse = true;
	int results = 0;

	for (int i = index; i < m;)
	{
		trueorFalse = true;

		for (int j = 0, ind = i; (j < vec.size() && j < m); ++j, ++ind)
		{
			if (vec[j] != chr[ind])
			{
				if (chr[ind] == 'I')
				{
					i = ind; 
				}
				else
				{
					i = ind + 1; 
				}
				trueorFalse = false;
				break;
			}
		}

		if (trueorFalse == true)
		{
			i = i + 2;
			results++;
		}
	}

	cout << results; 
	return 0; 

}