#include <iostream>
using namespace std;
const int MOD = 1000000007;
using ll = long long;
ll pow(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // nの最下位bitが1ならばx^(2^i)をかける
        x = x * x % MOD;
        n >>= 1;  // nを1bit右にシフト
    }
}
int main(void) {
    ll x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}