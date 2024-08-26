// 하노이탑 알고리즘 
#include<iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> vec;

void hanoi(int N, int start, int dest, int temp)
{
	if (N == 1)
	{
		vec.push_back(make_pair(start, dest));
		return;
	}
	hanoi(N - 1, start, temp, dest);
	vec.push_back(make_pair(start, dest));
	hanoi(N - 1, temp, dest, start);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int a; 
	cin >> a; 
	hanoi(a, 1, 3, 2);

	cout << vec.size() << "\n";
	for (auto& v : vec)
	{
		cout << v.first << " " << v.second << "\n";
	}
	return 0;
}