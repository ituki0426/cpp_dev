#include <iostream>
#include <vector>
using namespace std;
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

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
using ll = long long;
int N;
Graph G;
ll rec(int v, int p, ll& ans) {
    vector<ll> chs;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        chs.push_back(rec(e.first, v, ans) + e.second);
    }
    sort(chs.begin(), chs.end(), greater<ll>());
    if (chs.size() == 0)
        return 0;
    else if (chs.size() == 1)
        chmax(ans, chs[0]);
    else
        chmax(ans, chs[0] + chs[1]);
    return chs[0];
}
int main(void) {
    while (cin >> N) {
        G.assign(N, vector<Edge>());
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        ll ans = 0;
        rec(0, -1, ans);
        cout << ans << endl;
    }
}
