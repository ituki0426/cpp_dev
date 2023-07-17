#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main(void) {
    ll N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    ll siz = 0;
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > siz) siz = a;
        A[i] = a;
        B[i] = b;
    }
    siz = siz + 1;
    vector<ll> ruiseki(siz + 1, 0);
    for (ll i = 0; i < N; i++) {
        ruiseki[1] += B[i];
        ruiseki[A[i] + 1] -= B[i];
    }
    for (ll i = siz; i >= 1; i--) {
        for (ll j = i + 1; j <= siz; j++) {
            ruiseki[j] += ruiseki[i];
        }
    }
    for (ll i = 1; i <= siz; i++) {
        if (ruiseki[i] <= K) {
            cout << i << endl;
            return 0;
        }
    }
}