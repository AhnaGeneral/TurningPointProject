#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0); 

	vector<int> weight, high; 
	vector<pair<int, int>>  vec;
	int count; 

	int iweight, ihigh;
	cin >> count; 
	int index = count;
	while (count--)
	{
		cin >> iweight >> ihigh;
		vec.push_back(make_pair(iweight, ihigh));
	}

	for (int i = 0; i < index; i++)
	{
		int result = 0; 
		for (int j = 0; j < index; j++)
		{
			if (i == j)
				continue; 
			
			pair<int, int> temp = vec[i];
			if ((temp.first < vec[j].first) && (temp.second < vec[j].second))
			++result; 
		}
		cout << result+1 << " ";
	}

}
