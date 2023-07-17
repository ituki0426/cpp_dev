#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void dfs(int v, Graph& G, vector<bool>& seen, vector<int>& order) {
    seen[v] = true;
    for (auto v2 : G[v]) {
        if (seen[v2]) continue;
        dfs(v2, G, seen, order);
    }
    order.push_back(v);
    return;
}
int main(void) {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    rep(i, M) sort(G[i].begin(), G[i].end());
    vector<bool> seen(N, false);
    vector<int> order;
    rep(v, N) {
        // 頂点vが既に訪問済みであればorderに含まれるため、。スキップする、
        if (seen[v]) continue;
        // そうでなければ、頂点vを視点として深さ優先探索を行う。
        dfs(v, G, seen, order);
    }
    reverse(order.begin(), order.end());
    for (auto v : order) cout << v << " ";
    cout << endl;
}