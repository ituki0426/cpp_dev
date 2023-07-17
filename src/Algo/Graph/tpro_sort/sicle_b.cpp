#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        deg[b]++;
    }
    queue<int> que;
    for (int v = 0; v < N; v++)
        if (deg[v] == 0) que.push(v);
    vector<int> order;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        order.push_back(v);
        for (int nv : G[v]) {
            deg[nv]--;
            if (deg[nv] == 0) que.push(nv);
        }
    }
    if (order.size() != N)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
