#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

// --- 에라토스테네스 채 ---
// --- 연속된 소수의 합  ---

constexpr int limitedNumber = 4'000'000;
bool arr[limitedNumber];
vector<int> primeNumber;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;

	memset(arr, true, sizeof(arr));

	arr[0] = arr[1] = false;

	for (int i = 2; i <= N / 2; ++i) {
		for (int j = i + i; j <= N; j += i) {
			arr[j] = false;
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		if (arr[i])
		{
			primeNumber.emplace_back(i);
		}
	}
	int onePointIdx, twoPointIdx, counts = 0, sum = 0;

	if (primeNumber.size() != 0)
	{
		onePointIdx = twoPointIdx = 0;
		sum = primeNumber[onePointIdx];
	}
	else
	{
		cout << "0";
		return 0;
	}

	while (onePointIdx <= twoPointIdx && twoPointIdx < primeNumber.size())
	{
		if (sum == N)
		{
			counts++;
			twoPointIdx++;
			if (twoPointIdx >= primeNumber.size())
				break;
			sum += primeNumber[twoPointIdx];
		}
		else if (sum < N)
		{
			twoPointIdx++;
			if (twoPointIdx >= primeNumber.size())
				break;
			sum += primeNumber[twoPointIdx];
		}
		else if (sum > N)
		{
			sum -= primeNumber[onePointIdx];
			onePointIdx++;
		}
	}

	cout << counts;
	return 0;
}