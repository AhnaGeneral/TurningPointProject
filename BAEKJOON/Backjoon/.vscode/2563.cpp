// 색종이
#include <iostream>
using namespace std;
int arr[101][101];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int _x, _y;
		cin >> _x >> _y;

		for (int j = _x, count = 0; (j <= 100 && count < 10); ++j, count++)
		{
			for (int k = _y, county = 0; (k <= 100 && county < 10); ++k, county++)
			{
				arr[j][k]++;
			}
		}
	}
	int result = 0;

	for (int count = 1; count <= 100; count++)
	{
		for (int county = 1; county <= 100; county++)
		{
			if (arr[count][county])
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}