#include <iostream> 
#include <algorithm>
using namespace std;

// 서로소, 합집합 찾기 그래프
// 유니온 파인드 알고리즘.
int getParent(int* Parent, int x)
{
	if(Parent[x] == x) 
		return x;
	return Parent[x] = getParent(Parent, Parent[x]);
}

void Union(int* parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int Find(int* parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0; 
}
int main(void)
{
	int parent[11]; 
	for (int i = 1; i <= 10; i++)
	{
		parent[i] = i;
	}
	Union(parent, 1, 2);
	Union(parent, 2, 3);
	Union(parent, 3, 4);
	Union(parent, 5, 6);
	Union(parent, 6, 7);
	Union(parent, 7, 8);
	// parent [1] [2] [3] [4] [5] [6] [7] 
	//         1   1   1   1   5   5   5  
	cout << "1과 5는 연결되어있나요? " << Find(parent, 1, 5) <<endl;
	Union(parent, 1, 5);
	// parent [1] [2] [3] [4] [5] [6] [7] 
	//         1   1   1   1   1   5   5  
	cout << "1과 5는 연결되어있나요? " << Find(parent, 1, 5) << endl;

}