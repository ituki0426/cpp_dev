// AtCoder ABC 235 E - MST + 1 (水色, 500 点)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct UnionFind {
    vector<int> par;
    UnionFind() {}
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(int x, int y) { return root(x) == root(y); }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) { return -par[root(x)]; }
};
struct Edge {
    int x, y, w, id;
    Edge() {}
    Edge(int x, int y, int w, int id) : x(x), y(y), w(w), id(id) {}
    inline bool operator<(const Edge& e) const { return w < e.w; }
};

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<Edge> edges;
    rep(i, M + Q) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back(Edge(a, b, c, i));
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    vector<int> res(Q);
    for (const auto& e : edges) {
        if (e.id >= M)
            res[e.id - M] = !uf.same(e.x, e.y);
        else
            uf.merge(e.x, e.y);
    }
    rep(i, Q) cout << (res[i] ? "Yes" : "No") << endl;
}