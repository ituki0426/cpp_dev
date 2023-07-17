// アルゴ式:Q3. 階段ののぼり方
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] += dp[i - 2];
    }
    cout << dp[N] << endl;
}