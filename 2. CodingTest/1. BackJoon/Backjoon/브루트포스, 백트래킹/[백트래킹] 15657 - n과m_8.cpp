#include<iostream>
#include<algorithm>
using namespace std;

int arr[9], res[9];
int n, m;

void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; ++i)
		{
			cout << res[i] << " ";
		}
		cout << endl;
		return;
	}
	int xx = 0; 

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == xx)
			continue;

		if (cnt == 0 || (cnt > 0 && res[cnt - 1] <= arr[i]))
		{
			res[cnt] = arr[i];
			xx = res[cnt];
			dfs(++num, cnt + 1);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0,0);
	return 0;
}