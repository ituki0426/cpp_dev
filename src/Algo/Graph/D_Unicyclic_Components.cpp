#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
class UnionFind {
   public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : m_parentsOrSizes(n, -1) {}
    int find(int i) {
        if (m_parentsOrSizes[i] < 0) {
            return i;
        }
        return m_parentsOrSizes[i] = find(m_parentsOrSizes[i]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (-m_parentsOrSizes[a] < -m_parentsOrSizes[b]) {
                std::swap(a, b);
            }
            m_parentsOrSizes[a] += m_parentsOrSizes[b];
            m_parentsOrSizes[b] = a;
        }
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int size(int i) { return -m_parentsOrSizes[find(i)]; }

   private:
    vector<int> m_parentsOrSizes;
};

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    UnionFind uf(N);
    rep(i, M) { uf.merge(u[i], v[i]); }
    vector<int> vs(N), es(N);
    rep(i, N) vs[uf.find(i)]++;
    rep(i, M) es[uf.find(u[i])]++;
    if (v == es)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}