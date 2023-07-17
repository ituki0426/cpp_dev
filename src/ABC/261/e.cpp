#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define bit(x, i) (((x) >> (i)) & i)
int main(void) {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> op(n);
    rep(i, n) cin >> op[i].first >> op[i].second;
    vector<int> ans(n);
    rep(k, 30) {
        int crr = bit(c, k);
        rep(i, n) {
            vector<int> f(2);
            int x = bit(op[i].second, k);
            if (op[i].first == 1) f = {0 & x, 1 & x};
            if (op[i].first == 2) f = {0 | x, 1 | x};
            if (op[i].first == 3) f = {0 ^ x, 1 ^ x};
            crr = f[crr];
            ans[i] |= crr << k;
        }
    }
    for (auto a : ans) cout << a << endl;
}