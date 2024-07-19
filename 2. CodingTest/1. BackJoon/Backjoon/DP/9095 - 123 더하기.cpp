#include<iostream>
using namespace std;

int aResult = 0;

void Func(int pNum, int pTarget)
{
	if (pNum > pTarget)
		return;

	if (pNum == pTarget)
	{
		aResult++;
	}

	Func(pNum + 1, pTarget); 
	Func(pNum + 2, pTarget);
	Func(pNum + 3, pTarget);

}

int main(void)
{
	int mTC;

	cin >> mTC;

	while (mTC--)
	{
		int N;
		cin >> N; 

		Func(0, N);

		cout << aResult; 
		aResult = 0; 
	}

	return 0;
}