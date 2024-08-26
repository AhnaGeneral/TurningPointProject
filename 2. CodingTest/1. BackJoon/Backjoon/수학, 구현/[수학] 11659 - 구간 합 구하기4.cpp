#include<iostream>
#include<stdlib.h>
#include<memory.h>
using namespace std; 
#define MAX 100'001
int SumArr[MAX], Arr[MAX];
// ±¸°£ ÇÕ. 

int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    int N, S; 
    cin >> N >> S;
    memset(SumArr, 0, sizeof(SumArr));
    memset(Arr, 0, sizeof(Arr));

    for(int i=1; i<=N; ++i)
    {
        cin>>Arr[i]; 
        SumArr[i]=Arr[i]+SumArr[i-1];
    }
    int m_begin, m_end;

    for(int i=1; i<=S; ++i)
    {
        cin >> m_begin >> m_end; 
        cout << SumArr[m_end]- SumArr[m_begin-1]<<"\n";
    }
    return 0; 
}