#include <atcoder/all>
#include <iostream>
#include <vector>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;
int main(void) {
    int a, m;
    ll x;
    cin >> a >> m >> x;
    mint::set_mod(m);

    auto f = [&](auto f, ll x) -> pair<mint, mint> {
        if (x == 0) return {0, 1};
        auto [s, p] = f(f, x / 2);
        s += s * p;
        p *= p;
        if (x % 2 == 1) s = s * a + 1, p *= a;
        return {s, p};
    };
    mint ans = f(f, x).first;
    cout << ans.val() << endl;
    return 0;
}