#include <iostream>
using namespace std;

void star(int N, int i, int j)
{
	if (N == 1)
	{
		
	}
	else if (i % 3 == 1 && j % 3 == 1)
	{
		cout << " ";
	}
	
}

// 0. *********
// 1. * ** ** *
// 2. *********
// 3. ***   ***
// 4. * *   * *
// 5. ***   ***
// 6. *********
// 7. * ** ** *
// 8. *********

// 3, 4, 5 N % 3
int main()
{
	int N; 
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{

		}
	}
	return 0;
}