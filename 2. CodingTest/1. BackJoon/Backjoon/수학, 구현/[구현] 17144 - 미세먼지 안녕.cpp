// - 미세먼지가 확산한다. 
// - 네 방향으로
// - 공청 있거나, 칸이 없으면 확산x 
// - 

// - 공기청소기가 작동한다. 
// - 바람이 반시계 방향, 아래는 시계방향
// - 

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

pair<int, int> air[51][51]; 
//int changeValue[51][51];

pair<int, int> airPurifier;
vector<pair<int, int>> airs; 
int direction[4][2] = { {1, 0},{0, 1},{-1, 0},{0,-1} };
// 50*50 = 2500 * 1000 = 2'500'000번
int times = 1; 
int main(void)
{
	while (true)
	{
		int r, c, t;
		cin >> r >> c >> t;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin >> air[i][j].first; //본연의 값
				air[i][j].second = 0;	//더해질값

				if (air[i][j].first == -1)
				{
					airPurifier.first = i;
					airPurifier.second = j;
				}
			}
		}

		pair<int, int> currnetPurifier[2];
		currnetPurifier[0].first = airPurifier.first - 1;
		currnetPurifier[0].second = airPurifier.second;

		currnetPurifier[1].first = airPurifier.first;
		currnetPurifier[1].second = airPurifier.second;

		int nextUp_x;
		int nextUp_y;
		int nextDown_x;
		int nextDown_y;

		int prevUp_x = nextUp_x = currnetPurifier[0].first;
		int prevUp_y = nextUp_y = currnetPurifier[0].second;
		int prevDown_x = nextDown_x = currnetPurifier[1].first;
		int prevDown_y = nextDown_y = currnetPurifier[1].second;

		while (t--)
		{
			//if (times % 2 == 1)
			//{
				for (int i = 0; i < r; ++i)
				{
					for (int j = 0; j < c; ++j)
					{
						int defalutNum = air[i][j].first;
						int addNum = air[i][j].second;
						air[i][j].second = 0;
						air[i][j].first = defalutNum + addNum;

					}
				}

				for (int i = 0; i < r; ++i)
				{
					for (int j = 0; j < c; ++j)
					{
						int defalutNum = air[i][j].first;
						//int addNum = air[i][j].second;

						//air[i][j].first = defalutNum + addNum;

						if (air[i][j].first != -1 && air[i][j].first > 0)
						{
							int diffusionCount = 0;
							for (int k = 0; k < 4; ++k)
							{
								int x = i + direction[k][0];
								int y = j + direction[k][1];

								if (!(x < 0 || x >= r || y < 0 || y >= c)
									&& air[x][y].first != -1)
								{
									air[x][y].second += abs(defalutNum / 5);
									diffusionCount++;
								}
							}
							air[i][j].second -= (abs(defalutNum / 5) * diffusionCount);
						}
					}
				}
			//}
			// 이전 공기청정기 위치 
				pair<int, int> atempUp = { 0, 0 }; 
				pair<int, int> atempDown = { 0, 0 };

				pair<int, int> tempUp = { 0, 0 };
				pair<int, int> tempDown = { 0, 0 };

				atempUp		= air[currnetPurifier[0].first][currnetPurifier[0].second + 1];
				atempDown	= air[currnetPurifier[1].first][currnetPurifier[1].second + 1];

				for (int i = 1; i < c - 1; ++i)
				{
					tempUp 	= air[currnetPurifier[0].first][i + 1];
					tempDown = air[currnetPurifier[1].first][i + 1];

					air[currnetPurifier[0].first][i + 1] = atempUp;
					air[currnetPurifier[1].first][i + 1] = atempDown;

					//air[currnetPurifier[0].first][i + 1] = air[currnetPurifier[0].first][i];
					//air[currnetPurifier[1].first][i + 1] = air[currnetPurifier[1].first][i];
			
					atempUp = tempUp;
					atempDown = tempDown;
				}




			//else
			//{
				if (prevUp_y > 0 && prevUp_x == 0)
				{
					nextUp_y = prevUp_y - 1;
				}
				else if (prevUp_y < c - 1 && prevUp_x == airPurifier.first - 1)
				{
					nextUp_y = prevUp_y + 1;
				}
				else if (prevUp_y == c - 1 && prevUp_x > 0)
				{
					nextUp_x = prevUp_x - 1;
				}
				else if (prevUp_y == 0 && prevUp_x < airPurifier.first - 1)
				{
					nextUp_x = prevUp_x + 1;
				}

				if (nextUp_x == airPurifier.first - 1 && nextUp_y == airPurifier.second)
				{
					nextUp_y++;
				}


				if (prevDown_y == 0 && prevDown_x > airPurifier.first)
				{
					nextDown_x = prevDown_x - 1;
				}
				else if (prevDown_y < c - 1 && prevDown_x == airPurifier.first)
				{
					nextDown_y = prevDown_y + 1;
				}
				else if (prevDown_y == c - 1 && prevDown_x < r - 1)
				{
					nextDown_x = prevDown_x + 1;
				}
				else if (prevDown_y > 0 && prevDown_x == r - 1)
				{
					nextDown_y = prevDown_y - 1;
				}

				if (nextDown_x == airPurifier.first && nextDown_y == airPurifier.second)
				{
					nextDown_y++;
				}

				air[nextUp_x][nextUp_y].first = 0;
				air[nextUp_x][nextUp_y].second = 0;

				air[nextDown_x][nextDown_y].first = 0;
				air[nextDown_x][nextDown_y].second = 0;

				prevUp_x = nextUp_x;
				prevUp_y = nextUp_y;
				prevDown_x = nextDown_x;
				prevDown_y = nextDown_y;
			//}

			//times++;
		}



		int result = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				int defalutNum = air[i][j].first;
				int addNum = air[i][j].second;
				air[i][j].first = defalutNum + addNum;
				//air[i][j].second = 0;

				result += air[i][j].first;

			}
		}
		cout << result + 2;
	}
	return 0; 
}