// フェルマーの小定理を用いた逆元の計算
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// a^(-1) mod を計算する
ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }
int main(void) {
    // mod. 13での逆元を求める
    for (int i = 1; i < 13; i++) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
}