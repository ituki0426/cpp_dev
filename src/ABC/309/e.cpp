#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int N;
    int M;
    cin >> N >> M;
    vector<int> p(N);
    for (int i = 1; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> dp(N, -1);
    for (int i = 0; i < M; i++) {
        int x;
        int y;
        cin >> x >> y;
        x--;
        dp[x] = max(dp[x], y);
    }
    for (int i = 1; i < N; i++) dp[i] = max(dp[i], dp[p[i]] - 1);
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (dp[i] >= 0) ans++;
    cout << ans << endl;
    return 0;
}