#include <iostream>
using namespace std;
using ll = long long;
ll pow(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // nの最下位bitが1ならばx^(2^i)をかける
        x *= x;
        n >>= 1;  // nを1bit右にシフト
    }
    return ret;
}
int main(void) {
    ll x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}