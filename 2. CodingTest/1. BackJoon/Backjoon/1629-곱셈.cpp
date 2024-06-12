#include <iostream>
#include <math.h>
using namespace std;

unsigned long long power(int value, int n, int c)
{
	if (n == 1) return value % c;
	else
	{
		unsigned long long x = power(value, n / 2, c);
		if (n % 2) // odd
		{
			return x%c*x%c*(value%c)%c;
		}
		else // even
		{
			return x%c*x%c;
		}
	}
}

int main(void)
{
	int A, B, C; 
	cin >> A >> B >> C; 

	cout << power(A, B, C);
	return 0; 
}