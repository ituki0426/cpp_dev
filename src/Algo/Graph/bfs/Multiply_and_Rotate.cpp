#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using ll = long long;
using namespace std;
int main(void) {
    int a, N;
    cin >> a >> N;
    queue<ll> que;
    vector<ll> dist(10 * N, -1);
    auto pusn = [&](ll v, ll p) -> void {
        if (v >= 10 * N) return;
        if (dist[v] == -1) {
            dist[v] = dist[p] + 1;
            que.push(v);
        }
    };
    que.push(1);
    dist[1] = 0;
    while (!que.empty()) {
        ll x = que.front();
        que.pop();
        pusn(x * a, x);
        if (x % 10 != 0) {
            string sx = to_string(x);
            sx = sx.back() + sx.substr(0, sx.size() - 1);
            istringstream si(sx);
            ll x2;
            si >> x2;
            pusn(x2, x);
        }
    }
    cout << dist[N] << endl;
}