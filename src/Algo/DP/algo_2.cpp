// アルゴ式:Q2. 部分和問題
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    vector<int> W(N + 1, 0);
    for (int i = 0; i < N; i++) cin >> W[i];
    dp[0][0] = true;
    rep(i, N) {
        rep(j, M + 1) {
            if (!dp[i][j]) continue;
            dp[i + 1][j] = true;
            if (j + W[i] <= M) dp[i + 1][j + W[i]] = true;
        }
    }
    dp[N][M] ? cout << "Yes" << endl : cout << "No" << endl;
}