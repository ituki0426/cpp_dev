#include <iostream>
using namespace std;
using ll = long long;
int N;
ll W, weight[110], value[110];
ll dp[110][100100] = {0};
int main(void) {
    cin >> N >> W;
    for (int i = 1; i <= N; ++i) cin >> weight[i] >> value[i];
    for (int i = 1; i <= N; i++) {
        for (int sum_w = 1; sum_w <= W; sum_w++) {
            if (sum_w - weight[i] >= 0) {
                dp[i][sum_w] = max(dp[i - 1][sum_w],
                                   dp[i - 1][sum_w - weight[i]] + value[i]);
            } else {
                dp[i][sum_w] = dp[i - 1][sum_w];
            }
        }
    }
    cout << dp[N][W] << endl;
}