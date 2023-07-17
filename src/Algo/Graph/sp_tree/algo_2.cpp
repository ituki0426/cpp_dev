// 、最終的に採用する辺の数が K 未満の場合には、どのようにしても K
// 本を選ぶことができないため、-1 を出力します。
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct Edge {
    int u;
    int v;
    ll cost;
    bool operator<(const Edge& other) const { return (cost < other.cost); }
};
class UnionFind {
   public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : m_parentsOrSize(n, -1) {}
    int find(int i) {
        if (m_parentsOrSize[i] < 0) return i;
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) swap(a, b);
            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }
    bool connected(int a, int b) { return (find(a) == find(b)); }
    int size(int i) { return -m_parentsOrSize[find(i)]; }

   private:
    vector<int> m_parentsOrSize;
};
using Graph = vector<Edge>;
int main(void) {
    int V, E, K;
    cin >> V >> E >> K;
    Graph edges(E);
    for (auto& edge : edges) cin >> edge.u >> edge.v >> edge.cost;
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    ll sum = 0;
    int added_num = 0;
    for (const auto& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            if (added_num >= K) continue;
            uf.merge(edge.u, edge.v);
            sum += edge.cost;
            added_num += 1;
        }
    }
    if (added_num < K) sum = -1;
    cout << sum << endl;
}