#include <functional>  // greater
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
vector<int> TopologicalSort(const Graph& graph) {
    vector<int> indegress(graph.size(), 0);
    vector<int> result;
    for (const auto& edges : graph) {
        for (const auto& edge : edges) {
            indegress[edge]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i, (int)graph.size()) {
        if (indegress[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        const int from = que.top();
        que.pop();
        result.push_back(from);
        for (const auto& to : graph[from]) {
            if (--indegress[to] == 0) {
                que.push(to);
            }
        }
    }
    if (result.size() != graph.size()) return {};
    return result;
}
int main(void) {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        graph[s].push_back(t);
    }
    const vector<int> result = TopologicalSort(graph);
    if (result.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto v : result) {
        cout << v + 1 << endl;
    }
}