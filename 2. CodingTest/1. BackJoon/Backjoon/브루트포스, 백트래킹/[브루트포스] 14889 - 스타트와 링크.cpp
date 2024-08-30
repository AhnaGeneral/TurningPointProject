// Baekjoon 
#include <iostream> 
#include <vector>
#include <algorithm>
//#include <math.h>
using namespace std;

int Ability[21][21];
int n, min_dif = 1000;
int get_point_all(vector<int>& team_s, vector<int>& team_i)
{
	int sum_s = 0;
	int sum_i = 0; 
	for (int i = 0; i < team_s.size(); ++i)
	{
		for (int j = 0; j < team_s.size(); ++j)
		{
			sum_s += Ability[team_s[i]][team_s[j]];
			sum_i += Ability[team_i[i]][team_i[j]];
		}
	}
	return abs(sum_s - sum_i);
}
void DFS(vector<int>& team_s, vector<int>& team_i, int index)
{
	if (index == n)
	{
		if ((team_s.size() != n / 2) || team_i.size() != n / 2) 
		return; 
		
		min_dif = min(min_dif, get_point_all(team_s, team_i));
		return;
	}
	// index��°�� ������ team_s�� ������ ��
	team_s.push_back(index);
	DFS(team_s, team_i, index + 1);
	team_s.pop_back(); 
	// index��°�� ������ team_l�� ������ ��
	team_i.push_back(index);
	DFS(team_s, team_i, index + 1);
	team_i.pop_back();


}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	 cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Ability[i][j]; 
		}
	}
	//dfs - ��Ʈ��ŷ���� ���� �����ؼ� �� �����
	vector<int> team_s, team_i; 
	DFS(team_s, team_i, 0);
	cout << min_dif; 
}