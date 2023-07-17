// AtCoder ABC 305 F - Dungeon Explore (水色, 525 点)
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    auto read = [&](int v) -> vector<int> {
        int num;
        cin >> num;
        vector<int> adj(num);
        for (int i = 0; i < num; i++) cin >> adj[i];
        return adj;
    };
    vector<int> seen(N + 1, false);
    auto dfs = [&](auto self, int v) -> void {
        if (v == N) {
            string ok;
            cin >> ok;
            exit(0);
        }
        seen[v] = true;
        auto adj = read(v);
        for (auto v2 : adj) {
            if (seen[v2]) continue;
            cout << v2 << endl;
            self(self, v2);
            cout << v << endl;
            read(v);
        }
    };
    dfs(dfs, 1);
}