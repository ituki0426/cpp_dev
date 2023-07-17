// AtCoder ABC 211 D - Number of Shortest paths (茶色, 400 点)
#include <atcoder/all>
#include <iostream>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using Graph = vector<vector<int>>;
using mint = atcoder::modint1000000007;

int main(void) {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    vector<int> dp(N, -1);
    vector<mint> cnt(N, 0);
    que.push(0);
    dp[0] = 0;
    cnt[0] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : G[u]) {
            // 新たに更新される場合
            if (dp[v] == -1) {
                que.push(v);
                dp[v] = dp[u] + 1;
                cnt[v] = cnt[u];
            } else if (dp[v] == dp[u] + 1) {
                cnt[v] += cnt[u];
            }
        }
    }
    cout << cnt[N - 1].val() << endl;
}