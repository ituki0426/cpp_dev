#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = atcoder::modint998244353;
using namespace std;
mint dp[1005][1005];

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    mint ans = 0;
    mint im = mint(1) / m;
    rep(i, k) {
        rep(j, n) {
            mint now = dp[i][j] * im;
            for (int d = 1; d <= m; d++) {
                int nj = j + d;
                if (nj > n) nj = n - (nj - n);
                if (nj == n)
                    ans += now;
                else
                    dp[i + 1][nj] += now;
            }
        }
    }

    cout << ans.val() << endl;
    return 0;
}