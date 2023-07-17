// 頂点sからtに辿りつかるか
// 有向グラフを考える
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}
int main(void) {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    Graph G(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    seen.assign(N, false);
    dfs(G, s);
    if (seen[t])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}