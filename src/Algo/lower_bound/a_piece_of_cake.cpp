#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main(void) {
    ll W, H, N, A, B;
    cin >> W >> H >> N;
    vector<ll> p(N), q(N);
    rep(i, N) cin >> p[i] >> q[i];
    cin >> A;
    vector<ll> a(A + 1, 0);
    rep(i, A) cin >> a[i + 1];
    cin >> B;
    vector<ll> b(B + 1, 0);
    rep(i, B) cin >> b[i + 1];
    map<pint, int> num;
    rep(i, N) {
        int x = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        int y = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
        ++num[pint(x, y)];
    }
    int minv = N + 1;
    int maxv = -1;
    for (auto it : num) {
        minv = min(minv, it.second);
        maxv = max(maxv, it.second);
    }
    if (num.size() < (A + 1) * (B + 1)) minv = 0;
    cout << minv << " " << maxv << endl;
}