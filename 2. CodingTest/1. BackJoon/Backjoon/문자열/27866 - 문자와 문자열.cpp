#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string str;
	
	int mTC;

	cin >> str; 
	cin >> mTC;

	cout << str[mTC - 1];
	return 0;
}