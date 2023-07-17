#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<bool> f(N, false);
        f[i] = true;
        queue<int> Q;
        Q.push(i);

        while (Q.size() > 0) {
            int x = Q.front();
            Q.pop();
            for (int j = 0; j < G[x].size(); j++) {
                int y = G[x][j];
                if (f[y]) continue;
                f[y] = true;
                Q.push(y);
                ans++;
            }
        }
    }
    ans -= M;
    cout << ans << endl;
}