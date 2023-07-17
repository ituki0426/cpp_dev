#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int>>;
int main(void) {
    int N, M;
    cin >> N >> M;
    int MAX = 0;
    Graph graph(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : graph[v]) {
            if (dist[nv] != -1) continue;
            MAX = max(dist[v] + 1, MAX);
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    Graph ans(MAX+1);
    rep(i, N) {
        if (dist[i] != -1) ans[dist[i]].push_back(i);
    }
    for (auto v : ans) {
        sort(v.begin(), v.end());
        for (const auto nv : v) cout << nv << " ";
        cout << endl;
    }
}