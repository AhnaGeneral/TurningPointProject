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
		else if (idx == str.size() - 1)
		{
			string sub = str.substr(beginSubidx, idx);
			numbers.emplace_back(stoi(sub));
		}
	}

	for (int i = 0; i < operators.size(); ++i)
	{

	}
	return 0;
}