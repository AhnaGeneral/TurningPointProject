#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int facto(int num)
{
	if(num ==0) return 1;
	if (num == 1) return 1; 
	return num * facto(num - 1);
}
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin >> n;

	cout << facto(n); 
	
	string str = to_string(facto(n));
	reverse(str.begin(), str.end());

	int res = 0;
	for (auto& s : str)
	{
		if(s!='0')
			break;

		res++;
	}

	cout << res;

	return 0;
}