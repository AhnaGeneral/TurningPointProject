// Baekjoon - 1436 ¿µÈ­°¨µ¶ ¼ò

#include <iostream> 
#include <cmath>
#include <string>
using namespace std; 
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	int N, index = 0; 
	int num = 665; 

	cin >> N; 
	
	while (true)
	{
		if (index == N) break; 
		num++; 
		for (int i = 0; i < 10; i++) {
			if (num / (int)pow(10, i) % 1000 == 666) {
				index++; 
				break;
			}
		}
	}
	cout << num; 
	return 0;
}