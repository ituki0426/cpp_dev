#include <atcoder/all>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace atcoder;  //
using namespace std;
using mint = modint998244353;
using ll = long long;
using P = pair<ll, ll>;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<P> a(3);
    rep(i, 3) cin >> a[i].first >> a[i].second;
    set<P> st;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    map<P, mint> dp;
    dp[P(0, 0)] = 1;
    rep(i, n) {
        map<P, mint> p;
        swap(dp, p);
        for (auto [x, cnt] : p) {
            rep(j, 3) {
                P nx = x;
                nx.first += a[j].first;
                nx.second += a[j].second;
                if (st.count(nx)) continue;
                dp[nx] += cnt;
            }
        }
    }
    mint ans;
    for (auto s : dp) ans += s.second;
    cout << ans.val() << endl;
    return 0;
}
