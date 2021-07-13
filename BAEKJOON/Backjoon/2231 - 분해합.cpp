// Baekjoon - 2231 분해합
#include <iostream> 
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int N; 
	cin >> N;
	int digits;
	int result = N; 
	bool is = false;
	// 자릿수 알기 위해서 ... 
	for (int i = 1; i <= 6; i++)
	{
		//cout << N / pow(10, i) << " ";
		if ((N / pow(10, i))  < 1)
		{
			digits = i - 1;
			break;
		}
	}

	for (int i = N - 1; i >= 1; i--)
	{
		int sum = 0;
		int origin = i; // 198
		int accu = i; 
		for (int j = digits; j >= 1; j--)
		{		
			sum += (accu / pow(10, j));
			int Ten = pow(10, j);
			accu = accu % Ten;
			if (j == 1)
			{
				sum += accu;
			}
		}
		if ((origin + sum) == N)
		{
			is = true;
			if (result > origin)
			{
				result = origin;
			}
		}
	}
	if (is)
		cout << result;
	else
		cout << 0; 
	
}