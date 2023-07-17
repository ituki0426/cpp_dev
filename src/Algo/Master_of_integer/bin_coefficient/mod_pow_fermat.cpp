#include <iostream>
using ll = long long;
using namespace std;
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// a^{-1} mod を計算する
ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }
int main(void) {
    for (int i = 1; i < 13; i++) {
        cout << modpow(2, i, 13) << endl;
    }
}