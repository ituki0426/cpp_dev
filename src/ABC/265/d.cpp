#include <iostream>
#include <set>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int main(void) {
    int n;
    cin >> n;
    vector<ll> b(3);
    vector<int> a(n);
    rep(i, 3) cin >> b[i];
    rep(i, n) cin >> a[i];
    vector<ll> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    set<ll> st;
    rep(i, n + 1) st.insert(s[i]);

    rep(i, n + 1) {
        ll ns = s[i];
        rep(j, 3) {
            ns += b[j];
            if (!st.count(ns)) break;
            if (j == 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}