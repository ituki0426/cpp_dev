// 　根から最も遠い点までの距離を求める
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
template <typename T>
struct Edge {
    int to;
    T cost;
};
using Graph = vector<vector<Edge<ll>>>;

template <typename T>
pair<T, int> dfs(const Graph &G, int u, int par) {
    pair<T, int> reet = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs<T>(G, e.to, u);
        next.first += e.cost;
        reet = max(reet, next);
    }
    return ret;
}
template <typename T>
T tree_diamiter() {
    pair<T, int> p = dfs<T>(G, 0, -1);
    pair<T, int> q = dfs<T>(G, p.second, -1);
    return q.first;
}