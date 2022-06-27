// [분할 정복] 1780 - 종이의 개수 
#include <iostream> 
using namespace std;
// 3 9 27 81 243 729 2183
#define MAX 2200
int arr[MAX][MAX];
int result[3];

void DivideAndConquer(int _x, int _y, int _size)
{
    int value = arr[_y][_x];
    for (int i = _y; i < _y + _size; ++i)
    {
        for (int j = _x; j < _x + _size; ++j)
        {
            if (value != arr[i][j])
            {
                int DivideSize = _size / 3;
                DivideAndConquer(_x, _y, DivideSize);
                DivideAndConquer(_x + DivideSize, _y, DivideSize);
                DivideAndConquer(_x, _y + DivideSize, DivideSize);
                DivideAndConquer(_x + DivideSize, _y + DivideSize, DivideSize);
                DivideAndConquer(_x + (DivideSize * 2), _y, DivideSize);
                DivideAndConquer(_x, _y + (DivideSize * 2), DivideSize);
                DivideAndConquer(_x + (DivideSize * 2), _y + ((DivideSize) * 2), DivideSize);
                DivideAndConquer(_x + (DivideSize * 2), _y + DivideSize, DivideSize);
                DivideAndConquer(_x + DivideSize, _y + (DivideSize * 2), DivideSize);
                return; 
            }
        }
    }
    if (value == -1)
    {
        ++result[0];
    }
    else if (value == 1)
    {
        ++result[2];
    }
    else if (value == 0)
    {
        ++result[1];
    }
}

int main(void)
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    DivideAndConquer(0, 0, n);

    for (int i = 0; i < 3; ++i)
    {
        cout << result[i] <<endl;
    }
}