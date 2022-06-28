#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pairInt;

int v = 6;
vector<pairInt> adj[7];
bool visit[7];

struct compare {
    bool operator()(pairInt &lhs, pairInt &rhs) {
        return lhs.second > rhs.second;
    }
};

void Prim() {
    priority_queue<pairInt, vector<pairInt>, compare> pque;

    for (int i = 0; i < adj[1].size(); i++) pque.push(adj[1][i]);
    visit[1] = true;

    int cnt = 0;
    while (cnt < v - 1) {
        pairInt curline = pque.top();
        pque.pop();

        int node = curline.first;
        int weight = curline.second;

        if (visit[node]) continue;
        visit[node] = true;
        cnt++;
        cout << node <<" "<< weight;

        for (int i = 0; i < adj[node].size(); i++) {
            int nextnode = adj[node][i].first;
            if (!visit[nextnode]) pque.push(adj[node][i]);
        }
    }
}


int main() {

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

    printf("[MST]\n");
    Prim();

    return 0;
}