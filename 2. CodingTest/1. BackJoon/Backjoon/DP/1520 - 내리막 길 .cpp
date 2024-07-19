//== [ Çà·Ä °ö¼À ¼ø¼­ ] ==

#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int gMatrix[500][500];
int gCount = 0;
int m_row, m_col;
bool visit[500][500];
int dp[500][500];

int Func(int x, int y)
{
	if (y >= m_col || x >= m_row)
		return 0 ;

	if (x == 0 && y == 0) 
	{
		return 1; 
	}
	
	if (visit[x][y])
		return dp[x][y];

	if (gMatrix[x][y] < gMatrix[x][y - 1])
	{
		dp[x][y] = dp[x][y] + Func(x, y - 1);
	}
	
	if (gMatrix[x][y] < gMatrix[x - 1][y])
	{
		dp[x][y] = dp[x][y] + Func(x - 1, y);
	}

	if (gMatrix[x][y] < gMatrix[x][y + 1])
	{
		dp[x][y] = dp[x][y] + Func(x, y+1);
	}

	if (gMatrix[x][y] < gMatrix[x + 1][y])
	{
		dp[x][y] = dp[x][y] + Func(x + 1, y);
	}

	return dp[x][y]; 
}

int main(void)
{

	
	cin >> m_row >> m_col; 

	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_col; ++j)
		{
			cin >> gMatrix[i][j];
		}
	}
	cout << Func(m_row-1, m_col-1);
	//cout << gCount; 
	return 0; 
}