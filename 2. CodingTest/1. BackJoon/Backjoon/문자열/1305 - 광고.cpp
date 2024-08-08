#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str; 
vector<int> mTable;
int biggestNum = 0; 

void makeTable()
{
	int j = 0;
	mTable.assign(str.size(), 0);
	

	for (int i = 1; i < str.size(); ++i)
	{
		while ((j > 0) && str[i]!= str[j])
		{
			j = mTable[j - 1];
		}

		if (str[i] == str[j])
		{
			mTable[i] = ++j;
			biggestNum = (biggestNum > mTable[i]) ? biggestNum : mTable[i];
		}
	}
}

int main(void)
{
	int L;

	cin >> L; 
	cin >> str; 

	makeTable();

	cout << str.size() - biggestNum;
	return 0;
}