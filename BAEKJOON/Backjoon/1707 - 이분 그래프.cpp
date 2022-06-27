#include <iostream>
#include <string>
using namespace std; 
#define MAX 20'001
int gVertex[MAX];

int GetParent(int pX)
{
	if (pX == gVertex[pX]) return pX;
	else return gVertex[pX] = GetParent(gVertex[pX]); 
}

void Union(int _pX, int _pY)
{
	int ax = GetParent(_pX);
	int ay = GetParent(_pY); 
	
	if (ax > ay) 
		gVertex[ax] = ay; 
	else
		gVertex[ay] = ax;
}

bool Find(int _pX, int _pY)
{
	int ax = GetParent(_pX);
	int ay = GetParent(_pY);

	if (ax == ay)
		return true;
	else
		return false;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K; 
	cin >> K; 
	
	while (K--)
	{
		int V, E; 
		string str = "YES";
		
		cin >> V >> E; 
		
		for (int i = 1; i <= V; ++i) {
			gVertex[i] = i; 
		}
		//============================
		
		for (int i = 1; i <= E; ++i) {
			int u, v; 
			cin >> u >> v; 
			if (!Find(u, v))
				Union(u, v);
			else
				str =  "NO";
			
		}
		cout << str << "\n";
	}
	return 0; 
}