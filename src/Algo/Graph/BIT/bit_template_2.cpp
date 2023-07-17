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
    ll lower_bound(ll x) {
        if (x <= 0) {
            return 0;
        } else {
            ll i = 0;
            ll r = 1;
            while (r < n) r = r << 1;
            for (int len = r; len > 0; len = len >> 1) {
                if (i + len < n && a[i + len] < x) {
                    x -= a[i + len];
                    i += len;
                }
            }
            return i;
        }
    }
};