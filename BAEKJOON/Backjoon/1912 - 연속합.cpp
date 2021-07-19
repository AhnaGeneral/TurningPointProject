#include<iostream>
using namespace std; 
int arr[100'001]; 
int dp[100'001];
int dx[100'001];
int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 

	int n; cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; 
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1)
		{
			dp[i] = arr[i]; 
			dx[i] = arr[i];
			continue; 
		}
		

	}
}
