#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	string Long, Short;
	if (a.size() > b.size())
	{
		Long = a;
		Short = b;
	}
	else
	{
		Long = b;
		Short = a;
	}
	reverse(Long.begin(), Long.end());
	reverse(Short.begin(), Short.end());

	string str = "";
	bool DoRound = false;
	for (size_t i = 0; i < Short.size(); ++i)
	{
		int num = (Short[i] - '0') + (Long[i] - '0');
		if (DoRound) num += 1;
		if (num >= 10)
		{
			DoRound = true;
			num -= 10;
		}
		else
		{
			DoRound = false;
		}

		str += num + '0';
	}
	for (size_t i = Short.size(); i < Long.size(); ++i)
	{
		int num = (Long[i] - '0');

		if (DoRound) num += 1;
		if (num >= 10)
		{
			DoRound = true;
			num -= 10;
		}
		else
		{
			DoRound = false;
		}

		str += num + '0';
	}

	if (DoRound)
		str += '1';
	reverse(str.begin(), str.end());

	cout << str;

	return 0;
}


