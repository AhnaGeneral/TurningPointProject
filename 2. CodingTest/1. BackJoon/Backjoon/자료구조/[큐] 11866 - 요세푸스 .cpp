#include <iostream> 
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int N, M;
	cin >> N >> M;

	queue<int> Q1, Q2; 
	vector<string> result;
	for (int i = 1; i <= N; ++i)
	{
		Q1.push(i);
	}


	int i = 0; 
	result.push_back("<");
	while (true)
	{
		if (Q1.empty() && Q2.empty())
		{
			result.pop_back();
			break;
		}
		if (!Q1.empty() && Q2.empty())
		{
			while (true)
			{
				if (Q1.empty())
					break;

				++i;
				int Temp = Q1.front();
				Q1.pop();
				if (i == M)
				{
					i = 0;
					result.push_back(to_string(Temp));
					result.push_back(", ");
				}
				else
				{
					Q2.push(Temp);
				}
			}
		}
		else if (Q1.empty() && !Q2.empty())
		{
			while (true)
			{
				if (Q2.empty())
					break;

				++i;
				int Temp = Q2.front();
				Q2.pop();
				if (i == M)
				{
					i = 0;
					result.push_back(to_string(Temp));
					result.push_back(", ");
				}
				else
				{
					Q1.push(Temp);
				}
			}
		}
	}
	result.push_back(">");

	
	for (auto& a : result)
	{
		cout << a; 
	}
}