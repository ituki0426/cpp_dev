#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main(void) {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        // 無向グラフなので両方向に辺を張る
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    int ans = *max_element(dist.begin(),dist.end());
    cout << ans << endl;
}