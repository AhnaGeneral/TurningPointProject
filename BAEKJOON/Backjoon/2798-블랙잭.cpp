// Baekjoon - 2798 ºí·¢Àè
// ¿ÏÀü Å½»ö, ÀüÃ¼ Å½»ö

#include <iostream> 
#include <cmath>
#include <vector>
//int Result();

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	int N, M, data, result; 
	std::vector<int> vec;
	std::cin >> N >> M; 
	vec.reserve(3); 
	while (N--)
	{
		std::cin >> data;
		vec.push_back(data);
	}
	int _min = 1'000'000; 
	for (int i = 0; i < vec.size() - 2; i++) {
		for (int j = i + 1; j < vec.size() - 1; j++) {
			for (int k = j + 1; k < vec.size(); k++) {
				int tmp = vec[i] + vec[j] + vec[k]; 
				if (tmp > M) continue; 
				
				int diff = M - tmp; 
				if (diff == 0)
				{
					result = tmp;
					std::cout << result;
					return 0 ; 
				}
				else if (diff > _min)
				{
					continue; 
				}
				else
				{
					_min = diff;
					result = tmp; 
				}
			}
		}
	}

	std::cout << result;
}
