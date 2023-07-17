#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<vector<int> > dp(n, vector<int>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) dp[i][0] = (dp[i - 1][0] + dp[i][0]) % 998244353;
        if (a[i] != b[i - 1]) dp[i][0] = (dp[i - 1][1] + dp[i][0]) % 998244353;
        if (b[i] != a[i - 1]) dp[i][1] = (dp[i - 1][0] + dp[i][1]) % 998244353;
        if (b[i] != b[i - 1]) dp[i][1] = (dp[i - 1][1] + dp[i][1]) % 998244353;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % 998244353 << endl;
}