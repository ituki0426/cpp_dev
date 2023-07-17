#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
   public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : m_parentsOrSize(n, -1) {}
    int find(int i) {
        // -1は単体の頂点を表す。
        if (m_parentsOrSize[i] < 0) {
            return i;
        }
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                swap(a, b);
            }
            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int size(int i) { return -m_parentsOrSize[find(i)]; }

   private:
    vector<int> m_parentsOrSize;
};
struct Edge {
    int u;
    int v;
    long long cost;
    bool operator<(const Edge& other) const { return (cost < other.cost); }
};
int main(void) {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (auto& edge : edges) {
        cin >> edge.u >> edge.v >> edge.cost;
        --edge.u;
        --edge.v;
    }
    UnionFind uf(V);
    sort(edges.rbegin(), edges.rend());
    long long sum = 0;
    for (const auto& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            uf.merge(edge.u, edge.v);
            sum += edge.cost;
        }
    }
    cout << sum << endl;
}