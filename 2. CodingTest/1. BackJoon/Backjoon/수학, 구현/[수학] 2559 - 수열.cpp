#include<iostream>
#include<stdlib.h>
#include<queue>
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
    priority_queue<int> pq;
    cin >> N >> S;
    memset(SumArr, 0, sizeof(SumArr));
    memset(Arr, 0, sizeof(Arr));

    for(int i=1; i<=N; ++i)
    {
        cin>>Arr[i]; 
        SumArr[i]=Arr[i]+SumArr[i-1];
        if(i>=S)
        {
            pq.emplace(SumArr[i]-SumArr[i-S]);
        }
    }

    cout << pq.top(); 
    
    return 0;
}