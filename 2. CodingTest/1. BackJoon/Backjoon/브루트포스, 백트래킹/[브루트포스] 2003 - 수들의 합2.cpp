// �˰���: Two pointer
// n���� �ڿ���, M�� �Ǵ� ����� ��
/*�� ���� �����͸� �����Ͽ� �κ����� ���� �� �ִ� ������ �迭�� ������ �ڿ����̱� �����̴�.
start�� ������Ű�� �κ����� �����ϴ� ���� �����Ҽ� �ְ�, end�� ���� ��Ű�� �κ����� �����Ҽ� �ִٴ°��� ������ �� �ִ�. */


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