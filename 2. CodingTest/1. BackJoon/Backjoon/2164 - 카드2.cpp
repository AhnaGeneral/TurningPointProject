#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();

	int K; cin >> K;
	queue<int> que;
	for (int i = 1; i <= K; ++i)
	{
		que.push(i);
	}
	
	while (true)
	{
		if(que.size()==1)
		{
			cout << que.front();
			return 0;
		}
		que.pop();
		int temp = que.front();
		que.pop();
		que.push(temp);
	}
	return 0;
}