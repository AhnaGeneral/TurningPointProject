#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <memory.h>
using namespace std;
#define MAX 11 
#define MAXISLAND 7
using uPairII = pair<int, int>;

vector<uPairII> gvIsland;
vector<pair<uPairII, int>> gvIslandDist;
int gMap[MAX][MAX];
bool gMapVisit[MAX][MAX];       // 그룹 함수 실행 시 방문 체크
int gIslandGroupNum[MAX][MAX];  // 섬의 번호 붙이기 
int gDirection[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
int N, M;
int gIslandGroupCount;
int gUnionFind[MAXISLAND];


void InputFunc();
void CreateGroup();
void CreateGroupBFSFunc(int pX, int pY, int pGroupNum);
void BridgeConnection();
void FindAllBridge(int pX, int pY);
void IslandUnion(int pIsland01, int pIsland02); 
bool IslandFind(int pIsland01, int pIsland02);
int  GetParent(int pNum);
void MSTKruskal();

void InputFunc()
{
    cin >> N >> M;

    memset(gMapVisit, false, sizeof(gMapVisit));
    memset(gMap, 0, sizeof(gMap));

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < M; ++col) {
            cin >> gMap[row][col];
            if (gMap[row][col])
                gvIsland.emplace_back(make_pair(row, col));
        }
    }
}

void CreateGroup()
{
    int mGroupNum = 1;
    for (size_t idx = 0; idx < gvIsland.size(); ++idx) {
        int mY = gvIsland[idx].first;
        int mX = gvIsland[idx].second;

        if (!gMapVisit[mY][mX])
        {
            CreateGroupBFSFunc(mX, mY, mGroupNum);
            mGroupNum++;
        }
    }
    gIslandGroupCount = mGroupNum - 1; //그룹 개수 저장하기.
}

void BridgeConnection()
{
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < M; ++col) {
            if (gIslandGroupNum[row][col]) {
                FindAllBridge(col, row);
            }
        }
    }

    sort(gvIslandDist.begin(), gvIslandDist.end(),
        [](pair<uPairII, int> _Parm01, pair<uPairII, int> _Parm02) 
        {
            return _Parm01.second < _Parm02.second;
        });
}

void FindAllBridge(int pX, int pY)
{
    const int cDirectionNum = 4;
    int nXInitN = pX;
    int nYInitN = pY;

    for (int i = 0; i < cDirectionNum; ++i)
    {
        int dist = 0;
        int _mX = pX;
        int _mY = pY;

        while (true)
        {
            _mX += gDirection[i][0];
            _mY += gDirection[i][1];

            if (_mX < 0 || _mX >= M || _mY < 0 || _mY >= N)
                break;

            if (gIslandGroupNum[_mY][_mX] == gIslandGroupNum[nYInitN][nXInitN])
                break;

            if (gIslandGroupNum[_mY][_mX] && gIslandGroupNum[nYInitN][nXInitN] && (gIslandGroupNum[_mY][_mX] != gIslandGroupNum[nYInitN][nXInitN])) {
                if (dist >= 2)
                    gvIslandDist.push_back(make_pair(make_pair(gIslandGroupNum[_mY][_mX], gIslandGroupNum[nYInitN][nXInitN]), dist));

                break;
            }
            dist++;

        }

    }
}

void IslandUnion(int pIsland01, int pIsland02)
{
    pIsland01 = GetParent(pIsland01); 
    pIsland02 = GetParent(pIsland02);

    if (pIsland01 < pIsland02) gUnionFind[pIsland02] = pIsland01;
    else gUnionFind[pIsland01] = pIsland02;
}

bool IslandFind(int pIsland01, int pIsland02)
{
    pIsland01 = GetParent(pIsland01);
    pIsland02 = GetParent(pIsland02);

    if (pIsland01 == pIsland02) return true;
    else return false;
}

int GetParent(int pNum)
{
    if (gUnionFind[pNum] == pNum) return pNum; 
    else return gUnionFind[pNum] = GetParent(gUnionFind[pNum]);
}

void MSTKruskal()
{
    if (gvIslandDist.empty())
    {
        cout << -1; 
        return;
    }
    int ResultMst = 0; 
    
    for (int i = 0; i < MAXISLAND; ++i) {
        gUnionFind[i] = i;
    }

    for (auto& aIslandDist : gvIslandDist)
    {
        if (!IslandFind(aIslandDist.first.first, aIslandDist.first.second))
        {
            IslandUnion(aIslandDist.first.first, aIslandDist.first.second); 
            ResultMst += aIslandDist.second; 
        }
    }

    // 섬이 모두 연결되었는지 확인하기 위해 부모를 찾아서 비교한다
    // 모두 연결 되었다면 공통조상은 같을것이기 때문에 .. 너무 어려웠다..
    for (int i = 1; i < gIslandGroupCount; ++i)
    {
        int mParent01 = GetParent(gUnionFind[i]);
        int mParent02 = GetParent(gUnionFind[i + 1]);
        if (mParent01 != mParent02)
        {
            cout << -1;
            return;
        }
    }
    cout << ResultMst;
}

void CreateGroupBFSFunc(int pX, int pY, int pGroupNum)
{
    queue<pair<int, int>> que;
    que.emplace(make_pair(pX, pY));
    gIslandGroupNum[pY][pX] = pGroupNum;
    gMapVisit[pY][pX] = true;

    const int cDirectionNum = 4;

    while (!que.empty())
    {
        int _mX = que.front().first;
        int _mY = que.front().second;
        que.pop();
        for (int idx = 0; idx < cDirectionNum; ++idx) {
            int _mDirectionX = gDirection[idx][0] + _mX;
            int _mDirectionY = gDirection[idx][1] + _mY;

            if (_mDirectionX >= 0 && _mDirectionX < M && _mDirectionY >= 0 && _mDirectionY < N) {
                if (gMap[_mDirectionY][_mDirectionX] && !gMapVisit[_mDirectionY][_mDirectionX]) {

                    gMapVisit[_mDirectionY][_mDirectionX] = true;
                    CreateGroupBFSFunc(_mDirectionX, _mDirectionY, pGroupNum);
                }
                gMapVisit[_mDirectionY][_mDirectionX] = true;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    InputFunc();
    CreateGroup();
    BridgeConnection();
    MSTKruskal();
}