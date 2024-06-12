#include <iostream>
#include <deque>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <algorithm> // transform
using namespace std; 

// Ac�� ���� �迭�� ������ �ϱ� ���� ���� ��� 
// R(������) - �迭�� �ִ� ���� ������ ������ �Լ�
// D(������) - ù��° ���� ������ �Լ�
// �Լ��� �����ؼ� �ѹ��� ����� �� �ִ�. 

int main()
{
	ios::sync_with_stdio(false);

	int TestCase; cin >> TestCase; 
	while (TestCase--)
	{
		int n;
		string str, result;
		deque<int> deq;
		cin >> str;
		cin >> n;

		char a;
		bool IsError = false; 
		while (true)
		{
			cin >> a;
			if (a == '[')
			{
				if (n == 0)
				{
					cin >> a;
					break;
				}

				int Num; 
				cin >> Num;
				deq.push_back(Num);
			}
			else if (a == ',')
			{
				int Num;
				cin >> Num;
				deq.push_back(Num);
			}
			else if (a == ']')
			{
				break; 
			}
		}

		bool IsBack = false;
		for (char& chr : str)
		{
			if (chr == 'R')
			{
				//if (!deq.empty())
				//{
					if (IsBack)
					{
						IsBack = false;
					}
					else
					{
						IsBack = true;
					}
				//}

				//else
				//{
				//	cout << "error" << endl;
				//	IsError = true;
				//	break; 
				//}
			}
			else if (chr == 'D')
			{
				if (!deq.empty())
				{
					if (IsBack)
					{
						deq.pop_back();
						
					}
					else
					{
						deq.pop_front();
					}
				}
				else
				{
					cout << "error" << endl;
					IsError = true;
					break;
				}
			}
		}

		if (!IsError)
			cout << "[";

		while (!deq.empty())
		{
			if (deq.size() == 1)
			{
				if (IsBack) 
				{
					cout << to_string(deq.back());
				}
				else
				{
					cout << to_string(deq.front());
				}
			}
			else
			{
				if (IsBack)
					cout << to_string(deq.back()) << ",";
				else 
					cout << to_string(deq.front()) << ",";

			}
			if (IsBack)
				deq.pop_back();
			else
				deq.pop_front();
		}

		if (!IsError)
			cout << "]"<<endl;

		//transform(arrList.begin(), arrList.end(), back_inserter(vec),
		//	[](unsigned char ctr) -> unsigned char
		//	{
		//		if (isdigit(ctr)!=0)
		//		{
		//			return ctr; 
		//		}
		//	}
		//);
	}
}