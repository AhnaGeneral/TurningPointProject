#include<iostream>
using namespace std; 

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	
	int N; 
	
	cin >> N; 
	
	int result = 0;
	int rise = 1; 
	int count = 1; 
	while (true)
	{
		result += rise; 
		if (N <= result)
		{
			cout << count;
			return 0;
		}
		rise= count* 6;
		count++;
	}
}