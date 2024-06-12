// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	vector<pair<int, int>> xy;
	int N, X, Y; 
	cin >> N; 
	while (N--)
	{
		cin >> X >> Y; 
		xy.push_back(make_pair(X, Y)); 
	}
	
	sort(xy.begin(), xy.end()); 

	for (auto a : xy)
	{
		cout << a.first <<" "<< a.second;
		cout << "\n";
	}
	return 0; 
}