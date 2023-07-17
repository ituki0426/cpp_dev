// AOJのトポロジカルソートを解く
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>> ;
vector<int> topological_sort(Graph &G, vector<int> &indegree, int V) {
    vector<int> ans;
    queue<int> que;
    // 入次数が0の頂点をキューに入れる
    rep(i, V) if (indegree[i] == 0) que.push(i);
    // キューが空になるまで、操作1~3を繰り返す
    while (!que.empty()) {
        // キューの先頭を取り出す
        int v = que.front();
        que.pop();
        // その頂点と隣接している頂点の入次数を減らしし、０になればキューに追加
        rep(i, G[v].size()) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        ans.push_back(v);
    }
    return ans;
}

int main(void) {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    // 頂点の入次数を記録する配列
    vector<int> indeg(V, 0);
    rep(i, E) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v] += 1;
    }
    vector<int> ans = topological_sort(G, indeg, V);
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}