#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class BIT {
   public:
    ll n;
    vector<ll> a;
    BIT(ll n) : n(n), a(n + 1, 0) {}
    void add(ll i, ll x) {
        i++;
        if (i == 0) return;
        for (ll k = i; k <= n; k += (k & -k)) {
            a[k] += x;
        }
    }

    ll sum(ll i, ll j) { return sum_sub(j) - sum_sub(i - 1); }
    ll sum_sub(ll i) {
        i++;
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k -= (k & -k)) {
            s += a[k];
        }
        return s;
    }
};
int main(void) {
    ll N, Q;
    cin >> N >> Q;
    BIT bit(N);
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        bit.add(i, a);
    }
    for(ll i = 0; i < Q; i++){
        ll type;
        cin >> type;
        if(type == 0){
            ll p, x;
            cin >> p >> x;
            bit.add(p, x);
        }else{
            ll l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }
}