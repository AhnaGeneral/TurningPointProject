#include<iostream>
#include<queue>
using namespace std; 

int main(void)
{
	int N; //명령의 수 
	cin >> N; 
	queue<int> que;

	while (N--)
	{
		string str; 
		cin >> str;

		if (str=="push")
		{
			int pushNum; 
			cin >> pushNum; 
			que.push(pushNum);
		}
		else if (str == "size")
		{
			cout << que.size() << endl;
		}
		else if (str == "empty")
		{
			cout << que.empty() << endl;
		}
		else if (str == "front")
		{
			if (que.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << que.front() << endl;
			}
		}
		else if (str == "back")
		{
			if (que.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << que.back() << endl;
			}
		}
		else if (str == "pop")
		{
			if (que.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << que.front() << endl;
				que.pop();
			}
		}
	}
	return 0;
}