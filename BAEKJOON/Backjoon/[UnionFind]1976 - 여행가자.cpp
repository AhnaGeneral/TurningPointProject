#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getParent(vector<int>& parent, int a)
{
	if (parent[a] == a) return a; 
	return parent[a] = getParent(parent, parent[a]);
}

void Union(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a); 
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b; 
}

int Find(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main()
{
	int n, m; 
	cin >> n >> m; 
	vector<int> arr;
	arr.resize(n + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		arr[i] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a; 
			cin >> a; 
			if (a)
			{
				Union(arr, i, j);
			}
		}
	}

	vector<int> plan; 
	for (int i = 1; i <= m; ++i)
	{
		int a; cin >> a;
		plan.push_back(a);
	}

	for (int i = 0; i < m-1; ++i)
	{
		if (arr[plan[i]] != arr[plan[i + 1]])
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0; 
}