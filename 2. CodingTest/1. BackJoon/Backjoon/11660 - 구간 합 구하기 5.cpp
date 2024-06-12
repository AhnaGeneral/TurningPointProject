#include<iostream>
#include<stdlib.h>
#include<memory.h>
using namespace std;
#define MAX 1025 
int SumArr[MAX][MAX], Arr[MAX][MAX];


int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    memset(SumArr, 0 , sizeof(SumArr)); 
    memset(SumArr, 0 , sizeof(SumArr)); 

    int N, M;  // N: 표의 크기 M: 횟수 (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 
    cin >> N >> M; 

    for(int i=1; i<= N; ++i){
       for(int j=1; j<=N; ++j){
        cin >> Arr[i][j];
        SumArr[i][j] = Arr[i][j] + SumArr[i][j-1]; 
       }
    }

    int x1, y1, x2, y2, result; 
    for(int i=1; i<= M; ++i)
    {
       result = 0;
       cin >> x1 >> y1 >> x2 >> y2;
       
       for(int i=0; i<=(x2 - x1) ; ++i)
       {
       result += (SumArr[x2-i][y2] - SumArr[x2-i][y1-1]);
   
       }
           cout << result <<"\n"; 
    }


    return 0;
}