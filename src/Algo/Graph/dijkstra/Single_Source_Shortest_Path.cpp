// AOJ GRL_1_A - Single Source Shortest Path
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<ll, int>;
void Dijksra(const Graph& graph, vector<ll> distances, int startIndex) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> que;
    que.emplace((distances[startIndex] = 0), startIndex);
    while (!que.empty()) {
        const ll distance = que.top().first;
        const int from = que.top().second;
        que.pop();
        if (distances[from] < distance) continue;
        for (const auto& edge : graph[from]) {
            const ll d = distances[from] + edge.cost;
            if (distances[edge.to] <= d) continue;
            que.emplace((distances[edge.to] = d), edge.to);
        }
    }
}
int main(void) {
    int V, E, r;
    cin >> V >> E >> r;
    Graph graph(V);
    while (E--) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }
    vector<ll> distances(V, INF);
    Dijksra(graph, distances, r);
    for (const auto& d : distances) {
        if (d == INF)
            cout << "INF" << endl;
        else
            cout << d << endl;
    }
}