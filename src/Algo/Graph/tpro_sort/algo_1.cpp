// アルゴ式：Q7. トポロジカルソート (D)
//  https://algo-method.com/tasks/369
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int>>;
void dfs(int v, Graph& G, vector<bool>& seen, vector<int>& order) {
    seen[v] = true;
    for (auto v2 : G[v]) {
        if (seen[v2]) {
            continue;
        }
        dfs(v2, G, seen, order);
    }
    order.push_back(v);
    return;
}
int main(void) {
    int N, M;
    Graph G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    rep(i, N) sort(G[i].begin(), G[i].end());
    vector<bool> seen(N, false);
    vector<int> order(N);
    rep(v, N) {
        if (seen[v]) {
            continue;
        }
        dfs(v, G, seen, order);
    }
    reverse(order.begin(), order.end());
    rep(i, N) cout << order[i] << " ";
    cout << endl;
}