#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> p;

int v = 6;
vector<p> adj[7];
bool visit[7];

//우선순위 큐 정렬함수
struct compare {
    bool operator()(p a, p b) {
        return a.second > b.second;
    }
};

void Prim() {
    //큐 안의 간선들은 가중치 기준 오름차순으로 항상 정렬됨
    priority_queue<p, vector<p>, compare> pque;

    //출발지와 연결된 간선들을 모두 큐에 삽입
    for (int i = 0; i < adj[1].size(); i++) pque.push(adj[1][i]);
    visit[1] = true;

    int cnt = 0;
    while (cnt < v - 1) {
        p curline = pque.top();
        pque.pop();

        int node = curline.first;
        int weight = curline.second;

        //뽑은 간선의 목적지 노드가 이미 발견된 상태라면 선택하지 않음
        if (visit[node]) continue;
        visit[node] = true;
        cnt++;

        //현재 간선을 MST에 추가
        printf("%d번 정점 발견 : 비용 %d\n", node, weight);

        //뽑은 간선의 목적지 노드와 연결된 간선들을 모두 큐에 삽입
        for (int i = 0; i < adj[node].size(); i++) {
            int nextnode = adj[node][i].first;
            if (!visit[nextnode]) pque.push(adj[node][i]);
        }
    }
}

void init() {
    adj[1].push_back({ 2, 9 });
    adj[1].push_back({ 3, 4 });
    adj[1].push_back({ 4, 3 });
    adj[1].push_back({ 5, 1 });

    adj[2].push_back({ 1, 9 });
    adj[2].push_back({ 4, 4 });
    adj[2].push_back({ 5, 5 });

    adj[3].push_back({ 1, 4 });
    adj[3].push_back({ 6, 6 });

    adj[4].push_back({ 1, 3 });
    adj[4].push_back({ 2, 4 });
    adj[4].push_back({ 5, 2 });
    adj[4].push_back({ 6, 8 });

    adj[5].push_back({ 1, 1 });
    adj[5].push_back({ 2, 5 });
    adj[5].push_back({ 4, 2 });

    adj[6].push_back({ 3, 6 });
    adj[6].push_back({ 4, 8 });
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    init();

    printf("[MST]\n");
    Prim();

    return 0;
}