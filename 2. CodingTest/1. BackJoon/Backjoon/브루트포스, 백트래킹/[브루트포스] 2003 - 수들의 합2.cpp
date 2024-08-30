// 알고리즘: Two pointer
// n개의 자연수, M개 되는 경우의 수
/*두 개의 포인터를 조작하여 부분합을 구할 수 있는 이유는 배열의 값들이 자연수이기 때문이다.
start를 증가시키면 부분합이 감소하는 것을 보장할수 있고, end를 증가 시키면 부분합이 증가할수 있다는것을 보장할 수 있다. */


#include <iostream>

using namespace std;

int board[10001];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];

    int answer = 0;

    int start = 0;
    int end = 0;
    int partial_sum = 0;

    while (end <= N)
    {
        if (partial_sum == M)
            answer++;
            
        if (partial_sum >= M)
            ++start;
        else if (partial_sum < M)
            --end;
    }

    cout << answer << "\n";
}