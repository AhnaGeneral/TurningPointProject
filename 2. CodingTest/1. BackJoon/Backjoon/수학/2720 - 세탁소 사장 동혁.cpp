#include<iostream>
using namespace std;

int main(void)
{
	int mTC;

	cin >> mTC;

	int Quar = 25; 
	int dime = 10; 
	int nickel = 5; 
	int penny = 1; 

	while (mTC-- )
	{
		int CC; 
		cin >> CC; 
		// ============================= // 
		if (CC >= Quar)
		{
			cout << CC / Quar <<" ";
			CC = CC % Quar;
		}
		else
		{
			cout << 0 << " ";
		}
		// ============================= // 
		if (CC >= dime)
		{
			cout << CC / dime << " ";
			CC = CC % dime;
		}
		else
		{
			cout << 0 << " ";
		}
		// ============================= // 
		if (CC >= nickel)
		{
			cout << CC / nickel << " ";
			CC = CC % nickel;
		}
		else
		{
			cout << 0 << " ";
		}
		// ============================= // 
		if (CC >= penny)
		{
			cout << CC / penny << " ";
			CC = CC % penny;
		}
		else
		{
			cout << 0 << " ";
		}
		// ============================= // 
		
		cout << endl;
	}
	return 0;
}