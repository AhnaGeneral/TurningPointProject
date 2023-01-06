#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N; 
	vector<int> vec;
	for (int i = 0; i < N; ++i)
	{
		int P; 
		cin >> P; 
		vec.emplace_back(P);
	}
	sort(vec.begin(), vec.end()); 
	
	int sum = 0, Result = 0; 
	for (auto v : vec)
	{
		sum += v; // 0 + 1, 1 + 2, 3 + 3
		Result += sum;
	}

	cout << Result;
	return 0; 
}