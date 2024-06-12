// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int A; cin >> A;
	vector<char> chr;
	int result = 0; 
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		char c; 
		cin >> c; 
		chr.push_back(c);
	}

	for (int i = 2; i >=0; i--)
	{ 
		result = A * (chr[i] - '0');
		cout << result << "\n";
		result = result * pow(10, 2- i);
		sum += result;
	}

	cout << sum;

}