// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
char Arr[50][50];
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Arr[i][j];
		}
	}
	int distN = N - 8; // ex) 10 - 8 = 2 
	int distM = M - 8; // ex) 13 - 8 = 5 
	char current; 
	int count = 0;
	bool control = true;
	for (int i = 0; i <= distN; i++)
	{
		for (int j = 0; j <= distM; j++)
		{
			//current = Arr[i][j];
			for (int _N = 0; _N < 8; _N++) {
				if (_N)
				{
					if (Arr[_N - 1][j] == Arr[_N][j])
					{
						if (Arr[_N - 1][j] == 'B')
							current = 'B';
						else
							current = 'W';
					}
					else
					{
						control = false; 
					}
				}
				for (int _M = 0; _M < 8; _M++) {
					
					if (!control)
					{
						control = true;
						continue;
					}
					if (_M == 0&&_N == 0)
					{
						current = Arr[i][j];
						continue; 
					}
					if (current == 'B')
					{
						if (Arr[_N + i][_M + j] == 'B')
						{
							//Arr[_N + i][_M + j] = 'W';
							current = 'W'; 
							count++; 
						}
						else
						{
							current = 'W';
						}
					}
					else
					{
						if (Arr[_N + i][_M + j] == 'W')
						{
							//Arr[_N + i][_M + j] = 'B';
							current = 'B';
							count++;
						}
						else
						{
							current = 'B';
						}
					}
				}
			}
		cout << count << " ";
		count = 0;
		}
	}

}