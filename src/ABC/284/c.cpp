#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;

int main(void) {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(n, false);
    auto dfs = [&](auto dfs, int v) -> void {
        visited[v] = true;
        for (auto next_v : G[v]) {
            if (visited[next_v]) continue;
            dfs(dfs, next_v);
        }
    };
    int ans = 0;
    rep(v, n) {
        if (visited[v]) continue;
        dfs(dfs, v);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
