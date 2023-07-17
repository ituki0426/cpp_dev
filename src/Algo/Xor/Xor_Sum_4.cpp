#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
const int MOD = 1000000007;
int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll res = 0;
    ll two_factor = 1;
    rep(d, 60) {
        ll even = 0;
        ll odd = 0;
        rep(i, N) {
            if (A[i] & (1LL << d))
                odd++;
            else
                even++;
        }
        ll add = (odd * even) % MOD * two_factor % MOD;
        res = (res + add) % MOD;
        two_factor = (two_factor * 2) % MOD;
    }
    cout << res << endl;
}