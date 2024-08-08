#include<iostream>
using namespace std;
#define MAX_NUM 1'000'000'007
long long  dp[21] = { 0, };
long long factorial(int num)
{
	if (dp[num]) return dp[num] % MAX_NUM;;

	if (num == 0) return dp[0] = 0 % MAX_NUM;
	if (num == 1) return dp[1] = 1 % MAX_NUM;;

	return dp[num] = (factorial(num - 2) % MAX_NUM + factorial(num - 1) % MAX_NUM) ;
}

int main(void)
{
	long long mTC;

	

	while(cin >> mTC)
	cout << factorial(mTC) % MAX_NUM;

	return 0;
}