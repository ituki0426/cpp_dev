#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
const int INF = 1000100100;
template <class T>
inline bool chmin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
int V, E;
int G[20][20];
int dp[5000][20];
int main(void) {
    cin >> V >> E;
    REP(i, 20) REP(j, 20) G[i][j] = INF;
    REP(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    REP(i, 5000) REP(j, 20) dp[i][j] = INF;
    dp[0][0] = 0;
    REP(S, 1 << V) {
        REP(v, V) {
            REP(u, V) {
                if (S != 0 && !(S & (1 << u))) continue;
                if ((S & (1 << v)) == 0) {
                    if (v != u) chmin(dp[S | (1 << v)][v], dp[S][u] + G[u][v]);
                }
            }
        }
    }
    if (dp[(1 << V) - 1][0] != INF) {
        cout << dp[(1 << V) - 1][0] << endl;
    } else {
        cout << -1 << endl;
    }
}