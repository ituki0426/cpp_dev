#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    Graph G(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    queue<int> que;
    vector<int> dist(N, -1);
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
            if (nv == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}