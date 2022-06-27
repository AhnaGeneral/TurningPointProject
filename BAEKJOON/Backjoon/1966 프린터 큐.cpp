#include <iostream> 
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);

	int TestCase; cin >> TestCase; 
	deque<int> de;
	while (TestCase--)
	{
		string str; 
		
		cin >> str; 
		if (str == "push_back")
		{
			int c; cin >> c;
			de.push_back(c);
		}
		else if (str == "push_front")
		{
			int c; cin >> c;
			de.push_front(c);
		}
		else if (str == "pop_front")
		{
			if (de.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.front() << endl; 
				de.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (de.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.back() << endl;
				de.pop_back();
			}

		}
		else if (str == "size")
		{
			cout << de.size() << endl;
		}
		else if (str == "empty")
		{
			cout << de.empty() << endl;
		}
		else if (str == "front")
		{
			if (de.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.front() << endl;
			}
		}
		else if (str == "back")
		{
			if (de.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.back() << endl;
			}
		}
		

	}
	
}