#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N; std::cin >> N;
	std::vector<int> vec(N), result(N, -1);

	for (int i = 0; i < N; ++i)
	{
		int A; std::cin >> A;
		vec[i]=(A);
	}

	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = i + 1; j < N; ++j)
	//	{
	//		if (vec[i] < vec[j])
	//		{
	//			std::cout << vec[j] << " ";
	//			break;
	//		}
	//		if (j == N - 1)
	//		{
	//			std::cout << -1 << " ";
	//		}
	//	}
	//	if (i == N - 1)
	//	{
	//		std::cout << -1 << " ";
	//	}
	//}

	std::stack<int> st; 
	for (int i = 0; i < N; ++i)
	{
		while (!st.empty() && vec[st.top()] < vec[i])
		{
			result[st.top()] = vec[i];
			st.pop(); 
		}
		st.push(i);
	}

	for (int i = 0; i < N; i++) std::cout << result[i] << " ";
	return 0;

}