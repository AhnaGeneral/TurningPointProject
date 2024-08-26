#include<iostream>
#include<stdlib.h>
#include<string>
#include<memory.h>
using namespace std; 
#define MAX 200'001
int SumArr[26][MAX];
// ±¸°£ ÇÕ. 

int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    string str; 
    int cnt = 0; 

    memset(SumArr, 0, sizeof(SumArr));

    cin >> str;
    for(char& chr: str)
    {
        SumArr[chr-'a'][cnt]++; 
        for(int idx = 0; idx < 26; ++idx)
        {
            SumArr[idx][cnt] +=SumArr[idx][cnt-1];
        }
        cnt++;
    }   

    int que;
    cin >> que;

    for(int idx = 0; idx < que; ++idx)
    {
        char c; 
        int aBegin, aEnd ; 
        cin >> c >> aBegin >> aEnd;

         cout << SumArr[c - 'a'][aEnd] - SumArr[c - 'a'][aBegin-1] << "\n";
    }

    return 0;
}