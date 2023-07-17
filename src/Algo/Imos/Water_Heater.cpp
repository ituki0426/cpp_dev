// ABC183 Dを解く
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
const int MAX = 210000;
int main(void) {
    ll N, W;
    cin >> N >> W;
    auto solve = [&]() {
        vector<ll> num(MAX + 1, 0);
        rep(i, N) {
            ll s, t, w;
            cin >> s >> t >> w;
            num[s] += w;
            num[t] -= w;
        }
        rep(v, MAX) {
            num[v+1] += num[v];
            if(num[v] > W) return false;
        }
        return true;
    };
    cout << (solve() ? "Yes" : "No") << endl;
}