#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int> >;

void rec(const Graph& G, int v, int p = -1) {
    cout << v + 1 << " ";
    for (auto nv : G[v]) {
        if (nv == p) continue;
        rec(G, nv, v);
        cout << v + 1 << " ";
    }
}
int main(void) {
    int N;
    cin >> N;
    Graph G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, N) sort(G[i].begin(), G[i].end());
    rec(G, 0);
    cout << endl;
}