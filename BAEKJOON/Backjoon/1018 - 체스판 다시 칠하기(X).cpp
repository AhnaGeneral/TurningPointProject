// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50
char arr[MAX][MAX];
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	int N, M; cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j]; 

	int distN = N - 8; 
	int distM = M - 8;
	char prev;
	int count = 0;
	bool control = false;
	// B W B W B W B W 
	// W B W B W B W B
	for (int i = 0; i <= distN; i++) {
		for (int j = 0; j <= distM; j++) {
			
			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {

					if (n == 0 && m == 0) {
						prev = arr[i][j]; continue;
					}
					if (n != 0 && m == 0) { // 다음 행의 첫번째 열
						if (arr[i+n][j] == arr[i + n-1][j])
						{ //같으면...
							prev = arr[i + n - 1][j]; 
						}
						else // 다르면...
						{
							prev = arr[i + n][j]; 
							continue;
						}
					}
					if (prev == 'B') {
						if (arr[n + i][m + j] == 'B') {
							//arr[n + i][m + j] = 'W';
							prev = 'W';  count++;
						}
						else {
							prev = 'W';
						}
					}
					else {
						if (arr[n + i][m + j] == 'W') {
							//arr[n + i][m + j] = 'B';
							prev = 'B';  count++;
						}
						else {
							prev = 'B';
						}
					}

				}
			}
			cout << count << " "; 
			count = 0;
		}
	}
}