#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;

int main(void) {
    int n;
    int P;
    cin >> n >> P;
    mint p = mint(P) / 100;
    mint q = mint(1) - p;

    vector<bool> visited(n + 1);
    vector<mint> mem(n + 1);
    auto f = [&](auto f, int n) -> mint {
        if (n <= 0) return 0;
        if (visited[n]) return mem[n];
        mint res = 1;
        res += f(f, n - 2) * p;
        res += f(f, n - 1) * q;
        visited[n] = true;
        return mem[n] = res;
    };
    cout << f(f, n).val() << endl;
    return 0;
}
