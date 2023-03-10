// »öÁ¾ÀÌ
#include <iostream>
using namespace std;
int MatA[100][100], MatB[100][100];
//int SumAB[100][100];

int main(void)
{
	int AN, AM;
	cin >> AN >> AM;
	for (int i = 0; i < AN; ++i)
	{
		for (int j = 0; j < AM; ++j)
		{
			int data; 
			cin >> data; 
			MatA[i][j] = data;
		}
	}
	// =================================
	int BN, BM;
	cin >> BN >> BM;
	for (int i = 0; i < BN; ++i)
	{
		for (int j = 0; j < BM; ++j)
		{
			int data;
			cin >> data;
			MatB[i][j] = data;
		}
	}
	// =================================
	for (int i = 0; i < AN; ++i)
	{
		for (int k = 0; k < BM; ++k)
		{
			int sumAB = 0;
			for (int j = 0; j < AM; ++j)
			{
				sumAB += MatA[i][j] * MatB[j][k];
			}
			cout << sumAB << " ";
		}
		cout << endl;
	}

	//
	//for (int i = 0; i < AN; ++i)
	//{
	//	for (int k = 0; k < AN; ++k)
	//	{
	//			cout << SumAB[i][k] <<" ";
	//	}
	//	cout << endl;
	//}
	return 0;
}