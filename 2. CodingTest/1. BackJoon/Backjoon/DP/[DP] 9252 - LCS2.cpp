#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1'001][1'001] = { 0, };
int dp2[1'001][1'001] = { 0, };
//int counts = -1;
vector<char> results;
vector<string> sorts; 
int main()
{
	string A, B, C;
	cin >> A >> B >> C;

	sorts.push_back(A);
	sorts.push_back(B);
	sorts.push_back(C);

	sort(sorts.begin(), sorts.end(), [](string a, string b) {
		return a.size() > b.size();
		});

	string Long, Middle, Short;



	for (int i = 1; i <= sorts[0].size(); ++i)
	{
		for (int j = 1; j <= sorts[1].size(); ++j)
		{
			if (sorts[0][i - 1] != sorts[1][j - 1])
			{
				dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}

	
	int i = A.size();
	int j = B.size();

	while (i > 0 && j > 0)
	{
		if (sorts[0][i - 1] == sorts[1][j - 1])
		{
			results.push_back(sorts[0][i - 1]);
			--i; 
			--j;
		}
		else
		{
			if (dp[i - 1][j] == dp[i][j])
			{
				--i;
			}
			else if (dp[i][j - 1] == dp[i][j])
			{
				--j; 
			}
		}
	}
	reverse(results.begin(), results.end()); 


	for (int i = 1; i <= results.size(); ++i)
	{
		for (int j = 1; j <= sorts[2].size(); ++j)
		{
			if (results[i - 1] != sorts[2][j - 1])
			{
				dp2[i][j] = (dp2[i - 1][j] > dp2[i][j - 1]) ? dp2[i - 1][j] : dp2[i][j - 1];
			}
			else
			{
				dp2[i][j] = dp2[i - 1][j - 1] + 1;
			}
		}
	}

	cout << dp[results.size()][sorts[2].size()]; 
	
	//if (dp[A.size()][B.size()] == 0)
	//{
	//	cout << 0; 
	//}
	//else
	//{
	//	cout << dp[A.size()][B.size()] << "\n";
	//	for (auto a : results)
	//	{
	//		cout << a; 
	//	}
	//}



}