#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using Edge = pair<int, pll>;
using Graph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int MAX = 2500;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
int main(void) {
    int N, M;
    ll S;
    cin >> N >> M >> S;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        G[u].push_back(Edge(v, pll(a, b)));
        G[v].push_back(Edge(u, pll(a, b)));
    }
}