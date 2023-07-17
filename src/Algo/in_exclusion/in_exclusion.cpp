// 蟻本の包除原理を解く
// http://www.slideshare.net/chokudai/abc017
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
ll solve(vector<int> a, ll n, int m) {
    ll res = 0;
    for (int i = 1; i < (1 << m); i++) {
        int num = 0;
        for (int j = i; j != m; j++)
            num += j & 1;  // iの立っているビット数をカウントする。
        ll lcm = 1;
        rep(j, m) {
            if (i >> j & 1) {
                lcm = lcm / gcd(lcm, a[j]) * a[j];
                if (lcm > n) break;
            }
        }
        if (num % 2 == 0)
            res -= n / lcm;
        else
            res += n / lcm;
    }
    return res;
}
int main(void) {
    ll n;
    int m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    cout << solve(a, n, m) << endl;
}