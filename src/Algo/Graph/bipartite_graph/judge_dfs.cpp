// 二部グラフの判定
//  color[v] = 1 (黒確定)、0 (白確定)、-1 (未訪問)
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false;  // 同じ色が隣接したらダメ
            continue;
        }
        // 隣接頂点の色を変えて、再帰的に探索
        if (!dfs(G, next_v, 1 - cur)) return false;
    }
    return true;
}
int main(void) {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // 無向グラフなので両方向に辺を張る
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 探索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; v++) {
        if (color[v] != -1) continue;  // vが訪問済みの場合は探索しない
        if (!dfs(G, v)) is_bipartite = false;
    }
    if (is_bipartite)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}