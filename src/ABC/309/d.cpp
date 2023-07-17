#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
int main(void) {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    Graph G(N1 + N2);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dist_start(N1 + N2 + 1, -1);
    vector<int> dist_end(N1 + N2 + 1, -1);
    queue<int> que_start;
    queue<int> que_end;
    dist_start[0] = 0;
    dist_end[N1 + N2 - 1] = 0;
    que_start.push(0);
    que_end.push(N1 + N2 - 1);
    while (!que_start.empty()) {
        int v = que_start.front();
        que_start.pop();
        for (auto nv : G[v]) {
            if (dist_start[nv] != -1) continue;
            dist_start[nv] = dist_start[v] + 1;
            que_start.push(nv);
        }
    }
    while (!que_end.empty()) {
        int v = que_end.front();
        que_end.pop();
        for (auto nv : G[v]) {
            if (dist_end[nv] != -1) continue;
            dist_end[nv] = dist_end[v] + 1;
            que_end.push(nv);
        }
    }
    int start = *std::max_element(dist_start.begin(), dist_start.end());
    int end = *std::max_element(dist_end.begin(), dist_end.end());
    cout << start + end + 1 << endl;
}
