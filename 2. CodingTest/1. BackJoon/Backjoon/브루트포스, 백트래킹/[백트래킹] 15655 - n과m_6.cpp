#include<iostream>
#include<algorithm>
using namespace std; 

int arr[9],  res[9];
bool visit[9] = { false, };
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

	//int prevnum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (visit[i] == false && (cnt == 0 ||(cnt > 0 && res[cnt - 1] < arr[i])))
		{
			res[cnt] = arr[i];
			visit[i] = true;
		//	prevnum = arr[i]; 
			dfs(cnt + 1); 
			visit[i] = false;
		}
	}

	// (cnt = 0) i = 0 :: visit[0] = true , res[0] = arr[0], prevnum = arr[0] 
	// (cnt = 1) i == 0 은 방문 true 이니 i++
	// (cnt = 1) i = 1 :: visit[1] = true , res[1] = arr[1], prevnum = arr[1] 
	// (cnt = 2) cnt == m 같아서 출력해줌.
	// (cnt = 1) i = 1 인상태 visit[1] = false로 해주고 { } 끝났기 때문에 다음 인덱스
	// (cnt = 1) i = 2 :: visit[2] = true , res[1] = arr[2], prevnum = arr[1] 
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i]; 
	}
	sort(arr, arr + n); 
	dfs( 0);
	return 0; 
}