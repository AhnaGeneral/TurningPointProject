#include <iostream>
#include <string>
#include <math.h>
#include<cctype>
using namespace std;
// 2 
// 0 1 2 4 8 16 32 ... 
// ZZZZZ 36진법
// 35,  
// 01

// 2진법 
// 1 1 1 
// 1 2 4 = 7

// 
int main(void)
{
	string str;
	int mTC;

	cin >> str; 
	cin >> mTC;
	long long result = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		//char cha = str[i];

		long long num = 0;
		if (isalpha(str[i])) // 알파벳 ? 
		{
			num = str[i] - 'A' + 10;
		
		}
		else
		{
			num = str[i] - '0';
			//str[i] * pow(mTC, i);
		}
		result += num * pow(mTC, str.size()-i-1);
	}

	cout << result; 
	return 0;
}