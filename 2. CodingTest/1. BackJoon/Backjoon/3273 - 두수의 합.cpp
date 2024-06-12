
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main()
{
    int N, M;
    cin >> N;

    
    for (int i = 0; i < N; i++)
    {   
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cin >> M;
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = arr.size() - 1;
    int partial_sum = 0;
    int result = 0 ;

    while (end != start)
    {
        partial_sum = arr[start] + arr[end];
        if (partial_sum == M)
            result++;
            
        if (partial_sum >= M)
            --end;
           
        else if (partial_sum < M)
             ++start;
    }

    cout << result << "\n";
}