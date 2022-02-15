#include <iostream>
using namespace std;
#define MAX 500000

int getParent(int* parent, int a)
{
	if (parent[a] == a)
		return a; 
	return parent[a] = getParent(parent, parent[a]);
}
void Union(int* parent, int a, int b)
{
	a = getParent(parent, a); 
	b = getParent(parent, b);

	if (a < b) 
		parent[b] = a;
	else
		parent[a] = b; 
}
int Find(int* parent, int a, int b)
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
	int arr[MAX];
	int value = 0;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i; 
	}

	for(int i = 1; i <= m; ++i)
	{
		int _a, _b;
		cin >> _a >> _b;

		if (Find(arr, _a, _b))
		{
			cout << i; 
			return 0;
		}
		Union(arr, _a, _b);
	}
	
	cout << 0; 
	return 0;
	
}