// ABC 223 F - Parenthesis Checking
//  https://atcoder.jp/contests/abc223/tasks/abc223_f
#include <atcoder/all>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace atcoder;
pair<int, int> op(pair<int, int> a, pair<int, int> b) {
    return make_pair(min(a.first, a.second + b.first), a.second + b.second);
}
pair<int, int> e() { return make_pair(0, 0); }
int main(void) {
    int n;
    int q;
    string s;
    cin >> n >> q;
    cin >> s;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            v[i] = make_pair(1, 0);
        } else {
            v[i] = make_pair(0, 1);
        }
    }
    segtree<pair<int, int>, op, e> seg(v);
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1) {
            swap(v[l - 1], v[r - 1]);
            seg.set(l, v[l]);
            seg.set(r, v[r]);
        } else {
            if (seg.prod(l, r + 1) == make_pair(0, 0))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
