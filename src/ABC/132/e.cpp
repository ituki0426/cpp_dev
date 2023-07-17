// AtCoder ABC 132 E - Hopsotch Addict(青色, 500 点)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
using ll = long long;

int main(void) {
    int s, t;
    int N, M;
    cin >> N >> M;
    Graph G(N);
    vector<vector<ll>> dp(N, vector<ll>(3, -1));
    for (int i = 0; i < M; i++) {
        int u;
        int v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    cin >> s >> t;
    s--;
    t--;
    dp[s][0] = 0;
    queue<pint> que;
    que.push({s, 0});
    while (!que.empty()) {
        pint cur = que.front();
        que.pop();
        int v = cur.first;
        int parity = cur.second;
        for (auto nv : G[v]) {
            int np = (parity + 1) % 3;
            if (dp[nv][np] == -1) {
                dp[nv][np] = dp[v][parity] + 1;
                que.push({nv, np});
            }
        }
    }
    if (dp[t][0] == -1)
        cout << -1 << endl;
    else
        cout << dp[t][0] / 3 << endl;
}