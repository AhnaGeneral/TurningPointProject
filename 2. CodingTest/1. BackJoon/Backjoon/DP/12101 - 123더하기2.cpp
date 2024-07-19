#include <iostream>
#include <vector>
using namespace std;

int aResult = 0;
int n, k;
vector<int> vec; 
bool check = false; 

void Func(int pNum, int pTarget)
{
	if (pNum > pTarget)
	{
		vec.pop_back();
		return;
	}
	if (pNum == pTarget)
	{
		aResult++;

		if (aResult == k)
		{
			check = true; 
			for (int a = 0; a < vec.size(); ++a)
			{
				cout << vec[a]; 
				if (a != vec.size() - 1)
					cout << "+";
			}
		}
		vec.pop_back();
		return;
	}

	vec.emplace_back(1);
	Func(pNum + 1, pTarget); 

	vec.emplace_back(2);
	Func(pNum + 2, pTarget);
	
	vec.emplace_back(3);
	Func(pNum + 3, pTarget);

	if(!vec.empty())
	vec.pop_back();
}

int main(void)
{

	cin >> n >> k;

	Func(0, n);

	if (!check)
		cout << -1;

	return 0;
}