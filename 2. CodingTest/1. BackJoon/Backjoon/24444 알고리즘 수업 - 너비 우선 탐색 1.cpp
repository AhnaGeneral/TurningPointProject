#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
#define MAXR 100'001

void BFS(int start);
vector<int> Edge[MAXR];
vector<pair<bool, int>> visite( MAXR, make_pair(false, 0));
int gOrderOfVisit; 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, R;

	cin >> N >> M >> R;
	
	for (int i = 1; i <= M; ++i) {
		int u, v; 
		cin >> u >> v; 
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!Edge[i].empty())
			sort(Edge[i].begin(), Edge[i].end(), greater<>()); // - 24445번
			// sort(Edge[i].begin(), Edge[i].end()); // - 24444번
	}
	BFS(R);

	for (int i = 1; i <= N; ++i)
		cout << visite[i].second << "\n"; // endl -> "\n" 안하면 시간초과 ㄷㄷㄷ..
}

void BFS(int start)
{
	deque<int> que;
	que.emplace_back(start);
	visite[start].first = true;

	while (!que.empty())
	{
		int _next = que.front();
		que.pop_front();
		visite[_next].second = ++gOrderOfVisit;

		for(auto & e : Edge[_next]) {
			if (!visite[e].first) {
				visite[e].first = true;
				que.emplace_back(e);
			}
		}
	}
}
