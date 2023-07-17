#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n;
    int orig;
    cin >> n;
    orig = n;
    vector<int> div;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            div.push_back(d);
            while (n % d == 0) n /= d;
        }
    }
    if (n != 1) div.push_back(n);
    // nと互いに素でないものを数え上げる
    int m = div.size();
    int ans = 0;
    for (int bit = 1; bit < (1 << m); bit++) {
        int popcnt = 0;
        for (int j = bit; j != 0; j >>= 1)
            popcnt += j & 1;  // bitの立っている数を数える
        int mul = 1;
        for (int i = 0; i < m; i++)
            if (bit >> i & 1) mul *= div[i];
        // 集合の数による場合分け
        if (popcnt % 2 == 1)
            ans += orig / mul;
        else
            ans -= orig / mul;
    }
    // 互いに素もの = 全体から素でないものを引く
    ans = orig - ans;
    cout << ans << endl;
}