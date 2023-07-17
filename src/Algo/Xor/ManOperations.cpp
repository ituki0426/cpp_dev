#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main(void) {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> op(n);
    for (int i = 0; i < n; i++) {
        cin >> op[i].first >> op[i].second;
    }
    vector<int> ans(n);
    for (int k = 0; k < 30; k++) {
        vector<int> func = {0, 1};
        int crr = c & (1LL << k);  // ibit目の値
        for (int i = 0; i < n; i++) {
            vector<int> f(2);
            int x = op[i].second & (1LL << i);
            if (op[i].first == 1) f = {0 & x, 1 & x};
            if (op[i].first == 2) f = {0 | x, 1 | x};
            if (op[i].first == 3) f = {0 ^ x, 1 ^ x};
            func = {f[func[0]], f[func[1]]};
            crr = func[crr];
            ans[i] |= crr << k;
        }
    }
    for (auto a : ans) {
        cout << a << endl;
    }
}