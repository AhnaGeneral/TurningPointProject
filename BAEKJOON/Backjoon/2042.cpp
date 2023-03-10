#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);

	int T; 
	cin >> T; 

	while (T--)
	{
		int a; 
		cin >> a;
		int _sum =0;
		vector<int> vec; 
		for (int i = 0; i < a; ++i)
		{
			int x; 
			cin >> x;
			vec.push_back(x);
			_sum += x;
		}
		double res;
		res = _sum / a;
		int _count = 0;

		for (size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] > res)
			{
				_count++; 
			}
		}
		
		double dou = (double)_count /(double)a * 100;
		cout << fixed; 
		cout.precision(3);
		cout << dou <<"%"<< "\n";
	}
	return 0;
}