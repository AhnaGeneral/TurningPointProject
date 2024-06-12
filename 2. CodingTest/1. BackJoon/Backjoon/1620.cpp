#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;
bool btn[10];
int n, m;

int bruteforce(int pNum)
{
	int _cnt = 0;
	if (pNum == 0)
	{
		if (!btn[0])
			return 0;
		else
			return 1;
	}
	while (pNum)
	{
		int ciphers = pNum % 10;
		if (!btn[ciphers])
			return 0;
		_cnt++; 
		pNum /= 10;
	}
	return _cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<int> vec;
	memset(btn, true,  sizeof(btn));

	for (int i = 0; i < m; ++i)
	{
		int a; 
		cin >> a;
		btn[a] = false;
	}

	int startNum = abs(n - 100);
	
	for (int i = 0; i <= 500'000; ++i)
	{
		int _cnt = 0;
		_cnt = bruteforce(i);

		if (_cnt)
		{
			_cnt = abs(n - i) + _cnt;

			if (startNum > _cnt)
				startNum = _cnt;
		}
	}

	cout << startNum;
	return 0; 
}