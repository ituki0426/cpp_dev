#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<vector<int>> data(N, vector<int>(3, 0));
    vector<vector<int>> dp(N, vector<int>(N, 0));
    REP(i, N) REP(j, 3) cin >> data[i][j];
    dp[0][0] = data[0][0];
    dp[0][1] = data[0][1];
    dp[0][2] = data[0][2];
    FOR(i, 1, N) {
        REP(j, 3) {
            if (j == 0) {
                dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + data[i][j];
            } else if (j == 1) {
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + data[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + data[i][j];
            }
        }
    }
    cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2])) << endl;
}