// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int operatorArr[4];
// +, -, *, %
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	vector<int> vec, oper; 
	int n;
	int _max = -100'000'000, _min = 100'000'000;
	int result = 0;
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}

	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		if (x)
		{
			while (x--)
			{
				oper.push_back(i);
			}
		}
	}
	
	result = vec[0];
	do {
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper[i] == 0) {
				result = result + vec[i + 1];
				//cout << endl;
			}
			else if (oper[i] == 1) {
				result = result - vec[i + 1];
				//cout << endl;
			}
			else if (oper[i] == 2) {
				result = result * vec[i + 1];
				//cout << endl;
			}
			else if (oper[i] == 3) {
				result = result / vec[i + 1];
				//cout << endl;
			}
		}
		if (_min > result)
			_min = result;
		if (_max < result)
			_max = result;

		result = vec[0];
	} while (next_permutation(oper.begin(), oper.end()));


	cout << _max << "\n" << _min; 
	return 0;
	
}