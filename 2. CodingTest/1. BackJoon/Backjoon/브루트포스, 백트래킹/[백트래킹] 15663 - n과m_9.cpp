#include<iostream>
#include<algorithm>
using namespace std;

int n, m, arr[8], res[8];
bool visit[8] = { false, };

void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << res[i]<<" ";
		}
		cout << endl;
		return; 
	}

	int temp = 0; 
	for (int i = 0; i < n; ++i)
	{
		if (!visit[i] && arr[i] != temp)
		{
			res[cnt] = arr[i]; 
			temp = res[cnt];
			visit[i] = true;
			func(cnt + 1); 
			visit[i] = false; 
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

	sort(&arr[0], &arr[0] + n);

	func(0);
	return 0;
}