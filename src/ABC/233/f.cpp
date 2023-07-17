#include <algorithm>
#include <atcoder/all>
#include <iostream>
#include <vector>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
struct Edge {
    int to, id;
    Edge(int to, int id) : to(to), id(id) {}
};
int main(void) {
    int n;
    cin >> n;
    vector<int> P(n);
    rep(i, n) cin >> P[i];
    rep(i, n) P[i]--;
    int m;
    cin >> m;
    dsu t(n);
    vector<vector<Edge>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (t.same(a, b)) continue;
        t.merge(a, b);
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    vector<int> ans;
    rep(sv, n) if (t.leader(sv) == sv) {
        auto get = [&](auto& get, int target, int p) -> bool {
            if (P[v] == target) return true;
            for (auto e : G[v]) {
                if (e.to == p) continue;
                if (get(get, e.to, target, v)) {
                    ans.push_back(e.id);
                    swap(P[v], P[e.to]);
                    return true;
                }
            }
            return false;
        };
        auto dfs = [&](auto& dfs, int v, int p) -> void {
            for (auto e : G[v]) {
                if (e.to == p) continue;
                dfs(dfs, e.to, v);
            }
            if (!get(get, v, v, -1)) {
                cout << -1 << endl;
                exit(0);
            }
        };
        dfs(dfs, sv, -1);
    }
   
}