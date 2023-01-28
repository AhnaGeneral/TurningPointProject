#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<long long> solution;
	
	for (int idx = 0; idx < N; ++idx) {
		long long data; 
		cin >> data; 
		solution.emplace_back(data); 
	}
	sort(solution.begin(), solution.end());
	
	int point_one, point_two, RO, RT; 
	point_one = 0; point_two = solution.size() - 1;
	long long sum = LLONG_MAX;

	while (point_one <point_two)
	{
		if (sum > abs(solution[point_one] + solution[point_two]))
		{
			sum = abs(solution[point_one] + solution[point_two]); 
			RO = solution[point_one];
			RT = solution[point_two];
		}
		
		if (solution[point_one] + solution[point_two] <= 0)
			point_one++;
		else
			point_two--;
	}

	cout << RO << " " << RT;
	return 0; 
	
}