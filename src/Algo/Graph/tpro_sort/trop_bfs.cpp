#include <iostream>
#include <queue>
#include <vector>
#define rep (i, n) for (int i = 0; i < n; i++)
using namespace std;
struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
vector<int> trop_sort(const Graph &G) {
    vector<int> ans;
    int n = G.size();
    vector<int> indeg(n, 0);  // 入次数
    for (int i = 0; i < n; i++)
        for (auto e : G[i]) indeg[e.to]++;

    queue<int> que;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) que.push(i);
    while (!que.empty()) {
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            indeg[e.to]--;
            if (indeg[e.to] == 0) que.push(e.to);
        }
    }
    return ans;
}
int main(void) {}