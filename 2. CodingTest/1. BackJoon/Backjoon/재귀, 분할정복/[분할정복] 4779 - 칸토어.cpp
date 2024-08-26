#include<iostream>
#include<math.h>
using namespace std;

void factorial(int num)
{
	if (num == 0)
	{
		cout << "-";
		return;
	}
	// num = 3 --> size = 9 
	int size = pow(3, num - 1); 

	factorial(num - 1); 
	
	for (int i = 0; i < size; ++i)
	{
		cout << " ";
	}

	factorial(num - 1);
}

int main(void)
{
	int mTC;

	cin >> mTC;

	factorial(mTC);

	return 0;
}