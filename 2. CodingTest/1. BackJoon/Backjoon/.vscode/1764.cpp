#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c; 
	cin >> n >> c; 
	set<string> poket;
	vector<string> vec; 
	for (int i = 0; i < n+c; ++i)
	{
		string str;
		cin >> str;
		auto res = poket.insert(str);
		if (res.second == false)
			vec.push_back(str);
		// pair로 리턴값을 준다.
	}

    sort(vec.begin(), vec.end());

	cout << vec.size() << "\n";
    
	for (auto a : vec)
	{
		cout << a << "\n";
	}
	return 0; 
}