#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, N) {
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[N - 1][N - 1] << endl;
}