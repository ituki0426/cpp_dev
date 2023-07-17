// AtCoder ABC 211 D - Number of Shortest paths (茶色, 400 点)
#include <atcoder/all>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using mint = atcoder::modint1000000007;
using Graph = vector<vector<int>>;
int main(void) {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    vector<int> dist(N, -1);
    vector<mint> cnt(N, 0);
    que.push(0);
    dist[0] = 0;
    cnt[0] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : G[u]) {
            if (dist[v] == -1) {
                que.push(v);
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
            } else if (dist[v] == dist[u] + 1) {
                cnt[v] += cnt[u];
            }
        }
    }
}