// ´©ÀûÇÕ - Ã¼½ºÆÇ ´Ù½Ã Ä¥ÇÏ±â2 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int startB[2001][2001], startW[2001][2001];
int DPB[2001][2001], DPW[2001][2001];

int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;
	bool flag = true;
	int SumStartB = 0, SumStartW = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char chr; cin >> chr;

			if (i % 2 == 0) // Çà Â¦¼ö  
			{
				if (j % 2 == 0) // ¿­ Â¦¼ö 
				{
					(chr == 'B') ? (startB[i][j] = 0, startW[i][j] = 1) : (startB[i][j] = 1, startW[i][j] = 0);
				}
				else  // ¿­ È¦¼ö
				{
					chr == 'B' ? (startB[i][j] = 1, startW[i][j] = 0) : (startB[i][j] = 0, startW[i][j] = 1);
				}
			}
			else // Çà È¦¼ö
			{
				if (j % 2 == 0) // ¿­ Â¦¼ö 
				{
					chr == 'B' ? (startB[i][j] = 1, startW[i][j] = 0) : (startB[i][j] = 0, startW[i][j] = 1);
				}
				else  // ¿­ È¦¼ö
				{
					chr == 'B' ? (startB[i][j] = 0, startW[i][j] = 1) : (startB[i][j] = 1, startW[i][j] = 0);
				}
			}
			DPB[i][j] += DPB[i][j - 1] + DPB[i - 1][j] - DPB[i - 1][j - 1] + startB[i][j];
			DPW[i][j] += DPW[i][j - 1] + DPW[i - 1][j] - DPW[i - 1][j - 1] + startW[i][j];
		}
	}

	int answer = 10'000'000;
	for (int i = N; i >= K; --i)
	{
		for (int j = M; j >= K; --j)
		{
			int B = DPB[i][j] - DPB[i - K][j] - DPB[i][j - K] + DPB[i - K][j - K];
			int W = DPW[i][j] - DPW[i - K][j] - DPW[i][j - K] + DPW[i - K][j - K];
			answer = B < W ? min(answer,B) : min(answer, W);
		}
	}
	cout << answer; 
}