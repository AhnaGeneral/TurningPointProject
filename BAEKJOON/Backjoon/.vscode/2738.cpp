// 행렬 덧셈 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
short arrA[100][100], arrB[100][100];

int main(void)
{
    short N, M ; 
    cin >> N >> M ; 
    
    for(int i=0; i<N; ++i)
        for(int j =0; j<M; ++j)
         {
            cin >> arrA[i][j];
         }

    for(int i=0; i<N; ++i)
        for(int j =0; j<M; ++j)
         {
            cin >> arrB[i][j];
         }


    for(int i=0; i<N; ++i)
    {
       for(int j =0; j<M; ++j)
        {
           cout<< arrB[i][j] + arrA[i][j] <<" ";
        }
        cout <<endl ; 
    }
}