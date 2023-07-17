#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n + 1, 0);
    rep(i, n) s[i + 1] = s[i] + a[i];
    for (int k = 1; k <= n; k++) {
        ll ans = 0;
        for (int i = 0; i + k <= n; i++) {
            chmax(ans, s[i + k] - s[i]);
        }
        cout << ans << endl;
    }
}