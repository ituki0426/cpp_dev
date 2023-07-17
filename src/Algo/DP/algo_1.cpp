// アルゴ式:Q1. 部分和問題 (導入編)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N - 1);
    vector<vector<bool>> dp(N, vector<bool>(M, false));
    for (auto &a : A) cin >> a;
    dp[0][0] = true;
    rep(i, N - 1) {
        rep(j, M) {
            if (!dp[i][j]) continue;
            dp[i + 1][j] = true;
            if(j + A[i] < M) dp[i + 1][j + A[i]] = true;
        }
    }
    int ans = 0;
    for (auto v : dp[N - 1])
        if (v) ans++;
    cout << ans << endl;
}