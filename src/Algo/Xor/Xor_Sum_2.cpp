#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll res = 0;
    ll two_factor = 1;
    for (int d = 0; d < 60; d++) {
        ll even = 0;
        ll odd = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << d))
                ++odd;
            else
                ++even;
        }
        ll add = (odd * even) % MOD * two_factor % MOD;
        res = (res + add) % MOD;
        two_factor = (two_factor * 2) % MOD;
    }
    cout << res << endl;
}