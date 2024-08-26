#include <iostream>
using namespace std;
// �����佺�׳׽��� ü
// 1�� �Ҽ��� �ƴϴ�. 
// 2�� �Ҽ��̴� -> 2�� ����� �Ҽ��� �ƴϴ�. 
// 3�� �Ҽ��̴� -> 3�� ����� �Ҽ��� �ƴϴ�.
// 5�� �Ҽ��̴� -> 5�� ����� �Ҽ��� �ƴϴ�.

bool sosu(int _k)
{
	if (_k == 1||_k==0)
		return false;
	for (int i = 2; i * i <= _k; i++)
	{
		if (_k != i)
		{
			if (_k % i == 0) return false;
		}
		for (int j = i + i; j <= _k; j += i)
		{
			if (_k % j == 0) return false; 
		}
	}
	return true; 
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	int M, N, First, sum = 0; 
	cin >> M >> N; 
	bool botton = false; 
	for (int k = M; k <= N; ++k)
	{
		if (sosu(k))
		{
			if (!botton) First = k; 
			sum += k;
			botton = true;
		}
	}
	if (botton)
		cout << sum << endl << First;
	else
		cout << -1;
	return 0; 
}