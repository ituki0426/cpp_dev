#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int> >;

int main(void) {
    int n, m;
    cin >> n >> m;
    Graph to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    const int MX = 1e6;
    int count = 0;
    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, int v) -> void {
        seen[v] = true;
        if (count == MX) return;
        count++;
        for (auto next_v : to[v]) {
            if (seen[next_v]) continue;
            dfs(dfs, next_v);
        }
        seen[v] = false;
    };
    dfs(dfs, 0);
    cout << count << endl;
    return 0;
};