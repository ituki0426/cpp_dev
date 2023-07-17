// bitDPの例題
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); i++)
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
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<int> t(n);
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) cin >> t[i];
    rep(i, n) rep(j, n) cin >> d[i][j];
    vector<int> dp(1 << n, 1e9);
    dp[0] = 0;
    rep(bit, 1 << n) {
        rep(j, n) {
            if (!(bit >> j & 1)) {
                int sum = 0;
                rep(k, n) {
                    if (bit >> k & 1) sum += d[k][j];
                }
                chmin(dp[bit | (1 << j)],
                      dp[bit] + (sum + t[j] - 1) / t[j] * t[j]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}