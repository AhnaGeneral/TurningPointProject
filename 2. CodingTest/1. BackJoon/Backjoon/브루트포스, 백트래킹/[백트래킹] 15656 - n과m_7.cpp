#include<iostream>
#include<algorithm>
using namespace std;

int arr[9], res[9];
int n, m;

void dfs(int cnt)
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

	for (int i = 0; i < n; ++i)
	{
		res[cnt] = arr[i];
		dfs(cnt + 1);
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
	dfs(0);
	return 0;
}