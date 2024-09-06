#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string str;
	cin >> str; 

	string results = "";

	int counts = 0;
	for (auto& a : str)
	{
		++counts;
		cout << a;
		if (counts == 10)
		{
			counts = 0; 
			cout << "\n";
		}
	}
	return 0;
}