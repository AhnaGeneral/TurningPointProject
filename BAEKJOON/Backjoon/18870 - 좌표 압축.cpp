// Baekjoon 

#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int N; 
	map<int, vector<int>> _map;  
	cin >> N; 
	int x, _count=0; 

	int arr[1'000'000];
	while (N--)
	{
		cin >> x; 
		_map[x].push_back(_count++);
	}
	int num = 0;
	for (auto iter = _map.begin(); iter != _map.end(); iter++)
	{
		//vector<int> temp = iter->second; 
		//for (int i = 0; i < temp.size(); i++)
		//{
		//	arr[temp[i]] = num;
		//}
		//num++;
	}
	
	
	
	// 2:0 , 4:1, -10:2, 4:3, -9:4 
	// -10, -9, 2, 4, 4
}