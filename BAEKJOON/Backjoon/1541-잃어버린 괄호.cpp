#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string str; 
	cin >> str; 
	int beginSubidx = 0;
	vector<int> numbers; 
	vector<char> operators; 
	for (size_t idx = 0; idx < str.size(); ++idx)
	{
		if (str[idx] == '+' || str[idx] == '-')
		{
			string sub = str.substr(beginSubidx, idx);
			numbers.emplace_back(stoi(sub));
			operators.emplace_back(str[idx]);
			
			beginSubidx = idx + 1; 
		}
	}

	string sub = str.substr(beginSubidx);
	numbers.emplace_back(stoi(sub));

	bool minusCheck = false; 
	int _sum = numbers[0];
	for (int i = 0; i < operators.size(); ++i)
	{
		if (operators[i] == '+')
		{
			if (minusCheck) // true
			{
				_sum -= numbers[i+1];
				minusCheck = true;
			}
			else
			{
				_sum += numbers[i + 1];
				minusCheck = false;
			}

		}
		else if (operators[i] == '-')
		{
			_sum -= numbers[i + 1];
			minusCheck = true;
		}
	}

	cout << _sum;
	return 0;
}