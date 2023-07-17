#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N);
    rep(i, N) cin >> A[i];
    dp[0] = 0;
    dp[1] = A[1];
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 2] + 2 * A[i], dp[i - 1] + A[i]);
    }
    cout << dp.at(N - 1) << endl;
}