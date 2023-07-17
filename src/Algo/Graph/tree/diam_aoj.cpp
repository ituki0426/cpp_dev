#include <iostream>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
// pair.first : 距離 /　pair.second : 最遠点
pair<int, int> dfs(const Graph &G, int u, int par) {
    pair<int, int> ret = make_pair(0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
int tree_diamiter(const Graph &G) {
    pair<int, int> p = dfs(G, 0, -1);
    pair<int, int> q = dfs(G, p.second, -1);
    return q.first;
}
int main(void) {
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n) {
        int s, t, cost;
        cin >> s >> t >> cost;
        G[s].push_back({t, cost});
        G[t].push_back({s, cost});
    }
    cout << tree_diamiter(G) << endl;
}