#include<iostream>
#include<limits.h>
using namespace std; 

long long a, b;
int gResult = INT_MAX; 
void dfs(long long pA, long long pCount)
{
	if (pA > b)
		return ;
	if (pA == b)
	{
		if (pCount < gResult)
		{
			gResult = pCount; 
		}
		return;
	}
		

	//dfs(pA, pC);

	dfs(pA * 2, pCount + 1);

	long long pTemp = pA * 10 + 1; 
	if (pTemp <= b)
		dfs(pTemp, pCount + 1);
}

int main()
{
	cin >> a >> b; 
	dfs(a, 0);
	if (gResult == INT_MAX)
	{
		cout <<-1;
	}
	else
	{
		cout << gResult + 1;
	}
	return 0;
}