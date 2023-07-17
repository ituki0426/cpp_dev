// アルゴ式:Q2. 行きがけ順
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};
using Graph = vector<vector<Edge>>;
int main(void) {
    int N;
    cin >> N;
    Graph G(N);
    for (int from = 1; from < N; from++) {
        int to;
        cin >> to;
        G[from].push_back(Edge(to, 1));
        G[to].push_back(Edge(from, 1));
    }
    queue<int> que;
    vector<int> dist(N, -1);
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : G[v]) {
            int w = e.to;
            if (dist[w] != -1) continue;
            dist[w] = dist[v] + 1;
            que.push(w);
        }
    }
}