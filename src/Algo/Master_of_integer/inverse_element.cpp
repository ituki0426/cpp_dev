// 逆元の計算
#include <iostream>
using namespace std;
using ll = long long;
long long modinv(ll a, ll m) {
    ll b = m;
    ll u = 1;
    ll v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(void) {
    const int MOD = 1000000007;
    ll a = 12345678900000;
    ll b = 100000;
    a %= MOD;
    cout << a* modinv(b, MOD) % MOD << endl;
}