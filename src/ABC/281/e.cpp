#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using Monoid = pair<ll, ll>;
Monoid op(Monoid a, Monoid b) {
    return {a.first + b.first, a.second + b.second};
}
Monoid e() { return {0, 0}; }
int main(void) {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // 座標圧縮を準備
    vector<pair<ll, int>> comp(N);
    for (int i = 0; i < N; i++) comp[i] = {A[i], i};
    sort(comp.begin(), comp.end());
    vector<int> order(N);
    for (int i = 0; i < N; i++) order[comp[i].second] = i;
    segtree<Monoid, op, e> seg(N);
    auto f = [&](Monoid x) -> bool { return x.first <= K; };
    auto push = [&](ll x, int id) -> void { seg.set(id, {x, 1}); };
    auto pop = [&](ll x,int id) -> void { seg.set(id, e()); };
    auto get = [&]() -> ll {
        int r = seg.max_right(0, f);
        return seg.prod(0, r).second;
    };
    for (int i = 0; i < M; i++) push(A[i], order[i]);
    for (int i = 0; i < N - M + 1; ++i) {
        cout << get() << " ";
        if (i + M < N) {
            push(A[i + M], order[i + M]);
            pop(A[i], order[i]);
        }
    }
    cout << endl;
}
