#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int mTC;
	int B; 
	cin >> mTC;
	cin >> B; 
	vector<char> vec;
	while (mTC > 0)
	{
		char num = (mTC % B > 9) ? (mTC % B) - 10 + 'A' : (mTC % B);

		vec.push_back(num);
		//if (isalpha(num))
		//{
		//	//cout << num;
		//}
		//else
		//{
		//	//cout << (int)num;
		//}
		mTC = mTC / B; 
	}

	reverse(vec.begin(), vec.end());
	for (auto a : vec)
	{
		if (isalpha(a))
		{
			cout << a;
		}
		else
		{
			cout << (int)a;
		}
	}
	return 0;
}