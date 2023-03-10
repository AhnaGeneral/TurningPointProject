// 강한 결합 요소
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int>				vec[10'001];
vector<vector<int>>		SCC; 
int						ID, D[10'001]; 
stack<int>				s;
bool					finished[10'001];

int dDfs(int x)
{
	D[x] = ++ID;
	s.push(x); //스택에 자기 자신을 삽입

	int parent = D[x];
	for (int i = 0; i < vec[x].size(); ++i)
	{
		int y = vec[x][i];
		if (D[y] == 0)
			parent = min(parent, dDfs(y));
		else if (!finished[y])
			parent = min(parent, D[y]);
	}

	if (parent == D[x]) // 부모노드가 자기 자신인 경우
	{
		vector<int> scc; 
		while (true)
		{
			int t = s.top(); 
			s.pop(); 
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break; 
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return parent;
}


int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 

	int v, e; 
	cin >> v >> e; 

	for (int i = 0; i < e; ++i)
	{
		int a, b; 
		cin >> a >> b;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= v; ++i)
	{
		if (D[i] == 0) dDfs(i);
	}

	cout << SCC.size() << "\n";
	sort(SCC.begin(), SCC.end(),
		[](vector<int> a, vector<int> b) 
	{ return a[0] < b[0]; });
	for (int i = 0; i < SCC.size(); ++i)
	{
		for (int j = 0; j < SCC[i].size(); ++j)
		{
			cout << SCC[i][j] << " ";
		}
		cout <<"-1"<< "\n"; 
	}

	return 0; 
}