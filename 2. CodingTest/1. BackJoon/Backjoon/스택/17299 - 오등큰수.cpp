#include<iostream>
#include<stack>
#include<array>
using namespace std;

array<int, 1'000'000> arrFunc = {0, };
array<int, 1'000'000> sequence = { 0, };
array<int, 1'000'000> ngf = { 0, };
int main(void)
{
	int mTC; cin >> mTC;

	for (int i = 0; i < mTC; ++i)
	{
		int A; cin >> A; 
		arrFunc[A] = ++arrFunc[A];
		sequence[i] = A; 
	}

	stack<int> sak; 

	for (int j = mTC - 1; j >= 0 ; --j)
	{
		while (!sak.empty() && arrFunc[sequence[j]] >= arrFunc[sak.top()])
			sak.pop();

		if (!sak.empty()) // 스택이 비
		{
			int temp = sak.top();
			if (arrFunc[sequence[j]] < arrFunc[temp])
			{
				ngf[j] = temp;
			}
		}
		else
		{
			ngf[j] = -1; 
			// ex) 3
		}
		
		sak.push(sequence[j]);
		//if(sequence[j])
	}


	for (int i = 0; i < mTC; ++i)
	{
		cout << ngf[i] << " ";
	}

	//bool vool = false;
	//for (int i = 0; i < mTC; ++i)
	//{
	//	vool = false;
	//	for (int j = i + 1; j < mTC; ++j)
	//	{
	//		if (arrFunc[sequence[i]] < arrFunc[sequence[j]])
	//		{
	//			cout << sequence[j] << " ";
	//			vool = true; 
	//			break;
	//		}
	//	}
	//	if (!vool)
	//	{
	//		cout << -1 << " ";
	//	}
	//}
	return 0;
}