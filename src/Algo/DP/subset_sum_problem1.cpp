#include <iostream>
#include <vector>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using Graph = vector<vector<int>>;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> dic(N - 1);
    Graph dp(N, vector<int>(M, 0));
    REP(i, N - 1) cin >> dic[i];
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, M) {
            if (i + 1 < N) {
                dp[i + 1][j] += dp[i][j];
                for (const auto &e : dic) {
                    if (j + e < M) dp[i + 1][j + e] += dp[i][j];
                }
            }
        }
    }
    cout << dp[N - 1][M - 1] << endl;
}