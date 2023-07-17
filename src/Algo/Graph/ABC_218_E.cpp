#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class UnionFind {
   public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : m_parentsOrSize(n, -1) {}
    int find(int i) {
        if (m_parentsOrSize[i] < 0)
            return i;
        else
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
struct Edge {
    int u;
    int v;
    long long cost;
    bool operator<(const Edge &e) const { return (cost < e.cost); }
};
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    long long answer = 0;
    for (auto &edge : edges) {
        cin >> edge.u >> edge.v >> edge.cost;
        --edge.u;
        --edge.v;
        // 最初から全ての辺を除去したことにする
        answer += edge.cost;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    for (const auto &edge : edges) {
        if ((edge.cost < 0) || (!uf.connected(edge.u, edge.v))) {
            uf.merge(edge.u, edge.v);
            // 辺を戻したのでコストを引く
            answer -= edge.cost;
        }
    }
    cout << answer << endl;
}