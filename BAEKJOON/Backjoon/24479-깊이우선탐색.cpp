#include <iostream>
#include <vector>
#include <algorithm>
//#include <memory.h> // memset
using namespace std; 
#define MAXR 100'001
// # V : 정점 집합, E : 간선 집합, R : 시작 정점
// # 인접행렬과 인접리스트

vector<int> Edge[MAXR];
//int  OrderOfVisit[MAXR]; <- 이걸로 하면 시간초과.
vector<int> OrderOfVisit(MAXR, 0);
int  gOrderOfVisit;
void DFS(int start);
int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0); 

	int N, M, R;

	cin >> N >> M >> R; 
	
	for (int i = 0; i < M; ++i) {
		int u, v; 
		cin >> u >> v; 
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		//sort(Edge[i].begin(), Edge[i].end(), [](int _E01, int _E02) {return _E01 > _E02; });
		sort(Edge[i].begin(), Edge[i].end(), greater<>());

	}
	DFS(R);

	for (int i = 1; i <= N; ++i)
	{
		cout << OrderOfVisit[i] << "\n";
	}
}

void DFS(int start)
{
	OrderOfVisit[start] = ++gOrderOfVisit;

	for (auto& aEdge : Edge[start]) {

		if (OrderOfVisit[aEdge])
			continue; 

		DFS(aEdge);
	}
}
