#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] += dp[i - 2];
        dp[i] += dp[i - 3];
    }
    cout << dp[N] << endl;
}