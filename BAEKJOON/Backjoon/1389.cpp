#include<iostream>
#include<vector>
using namespace std; 
// 케빈 베이컨의 6단계의 법칙 

vector<int> user[101];
int	relation[101][101];

void BFS(int pPos, int pTwo, int pCnt)
{
	for (int i = 0; i < user[pTwo].size(); ++i)
	{
		relation[pPos][user[pTwo][i]] = pCnt;
		
		BFS(pPos, user[pTwo][i], ++pCnt);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m; 
	cin >> n >> m; 

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		user[a].push_back(b); 
		user[b].push_back(a);
	}
	
	for (int i = 1; i <= n; ++i)
	{
		BFS(i, i, 1);
	}

	return 0; 
}