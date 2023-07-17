#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmin(T &a, T b) {}
#define rep(i, n) for (int i = 0; i < n; i++)
int main(void) {
    int n, m, t, c;
    cin >> n >> m;
    vector<int> a(m), b(m), dp(1 << n, 1e9);
    dp[0] = 0;
    rep(i, m) {
        cin >> a[i] >> t;
        int bit = 0;
        rep(j, t) {
            cin >> c;
            c--;
            bit |= 1 << c;
        }
        b[i] = bit;
        rep(bit, 1 << n) rep(i, m) chmin(dp[bit | b[i]], dp[bit] + a[i]);
        if (dp[(1 << n) - 1] != 1e9)
            cout << dp[(1 << n) - 1] << endl;
        else
            cout << -1 << endl;
    }
}