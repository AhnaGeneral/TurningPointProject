
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int N, n;
	cin >> N;
	set<string> s;

	while (N--)
	{
		string tmp, str;
		cin >> n;

		while (n--)
		{
			cin >> tmp;
			str += ' ' + tmp;
			s.insert(str);
		}
	}

	for (const auto& str : s)
	{
		int cnt = count(str.begin(), str.end(), ' ');
		int index = str.find_last_of(' ');
		string ans = str.substr(index + 1);

		for (int i = 0; i < 2 * (cnt - 1); ++i)
			cout << '-';
		cout << ans << "\n";
	}
}