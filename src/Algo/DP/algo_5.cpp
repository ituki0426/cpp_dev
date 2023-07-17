#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector<int>(M, -1));
    vector<int> A(N - 1);
    vector<int> B(N - 1);
    rep(i, N - 1) cin >> A[i];
    rep(i, N - 1) cin >> B[i];
    dp[0][0] = 0;
    rep(i, N - 1) {
        rep(j, M) {
            if (dp[i][j] == -1) continue;
            chmax(dp[i + 1][j], dp[i][j]);
            if (j + A[i] < M) chmax(dp[i + 1][j + A[i]], dp[i][j] + B[i]);
        }
    }
    if (dp[N - 1][M - 1] == -1)
        cout << -1 << endl;
    else
        cout << dp[N - 1][M - 1] << endl;
}