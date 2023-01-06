#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, K;
	vector<int> vec;
	cin >> N >> K;


	for (int i = 0; i < N; ++i)
	{
		int coinvalue;
		cin >> coinvalue;
		vec.emplace_back(coinvalue);
	}

	int _count = 0;

	for (int j = K; j != 0; )
	{
		int _min = 100'000'000;
		int value = 0;
		for (int i = 0; i < N; ++i)
		{
			if (K / vec[i])
			{
				if (K / vec[i] < _min)
				{
					value = vec[i];
					_min = (K / vec[i]); 
				}
			}
		}
		if (value != 0)
		{
			_count += K / value; 
			K = K % value;
		}
		j = K;
	}

	cout << _count;

}