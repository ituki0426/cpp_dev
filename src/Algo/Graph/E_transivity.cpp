//BFSによる実装
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        E[u - 1].push_back(v - 1);
    }
    int ans = 0;
    rep(i, N) {
        vector<bool> f(N);
        f[i] = true;
        queue<int> Q;
        Q.push(i);
        while (Q.size() > 0) {
            int x = Q.front();
            Q.pop();
            rep(j, E[x].size()) {
                int y = E[x][j];
                if (f[y]) continue;
                f[y] = true;
                Q.push(y);
                ans++;
            }
        }
    }
    ans -= M;
    cout << ans << endl;
    return 0;   
}