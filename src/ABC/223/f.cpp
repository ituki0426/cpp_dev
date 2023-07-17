#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
pair<int, int> op(pair<int, int> a, pair<int, int> b) {
    return make_pair(min(a.first, a.second + b.first), a.second + b.second);
}
pair<int, int> e() { return make_pair(0, 0); }
int main(void) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            v[i] = make_pair(1, 0);
        else
            v[i] = make_pair(0, 1);
    }
}

