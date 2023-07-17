#include <algorithm>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int N, H[100009];
int dp[100009];
int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i + 1];
    dp[0] = dp[1] = 0;
    dp[2] = abs(H[2] - H[1]);
    for (int i = 3; i <= N; i++)
        dp[i] = min(dp[i - 1] + abs(H[i] - H[i - 1]),
                    dp[i - 2] + abs(H[i] - H[i - 2]));
    cout << dp[N] << endl;
}