#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using Edge = pair<int, ll>;          // 辺
using Graph = vector<vector<Edge>>;  // グラフ
const ll INF = 1LL << 60;

int main(void) {
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];
    Graph G(N);
    rep(i, N - 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    // 　木dp
    vector<ll> dpfull(N, -INF), dprem(N, -INF);
    auto rec = [&](auto self, const Graph &G, int v, int p) -> void {
        ll base = 0;
        vector<ll> diff;
        for (auto e : G[v]) {
            if (e.first == p) continue;
            self(self, G, e.first, v);
            base += dpfull[e.first];
            diff.push_back(dpfull[e.first] - dprem[e.first]);
        }
        ll fulladd = 0;
        ll remadd = 0;
        sort(diff.begin(), diff.end(), greater<ll>());
        for (int i = 0; i < min(d[v], (int)diff.size()) && diff[i] >= 0; ++i) {
            fulladd += diff[i];
            if (i < d[v] - 1) remadd += diff[i];
        }
        dpfull[v] = base + fulladd;
        dprem[v] = base + remadd;
    };
    rec(rec, G, 0, -1);
    cout << dpfull[0] << endl;
}