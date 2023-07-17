// アルゴ式: 連続ボーナス (1)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int main(void) {
    int N, A;
    cin >> N >> A;
    vector<int> P(N), Q(N), R(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    rep(i, N) cin >> R[i];
    vector<vector<int>> dp(3, vector<int>(N, 0));
    dp[0][0] = P[0];
    dp[0][1] = P[1];
    dp[0][2] = P[2];
    rep(i, N) {
        rep(j, 3) {
        }
    }
}