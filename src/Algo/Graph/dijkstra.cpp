#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include<functional>
using namespace std;
struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<long long, int>;
constexpr long long INF = (1LL << 60);
void Dijkstra(const Graph& graph, vector<long long>& distances,
              int startIndex) {
    // priority_queue<Pair> qを降順にすると、priority_queue<Pair, vector<Pair>,
    // greater<Pair>> q;
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);
    while (!q.empty()) {
        const long long distance = q.top().first;
        const int from = q.top().second;
        q.pop();
        if (distances[from] < distance) {
            continue;
        }
        for (const auto& edge : graph[from]) {
            const long long d = (distances[from] + edge.cost);
            if (d < distances[edge.to]) {
                q.emplace((distances[edge.to] = d), edge.to);
            }
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
        Graph g(V);
        graph[s].push_back({t, d});
    };
    vector<long long> distances(V, INF);
    Dijkstra(graph, distances, r);
    for (const auto& distance : distances) {
        if (distance == INF) {
            cout << "INF" << endl;
        } else {
            cout << distance << endl;
        }
    }
}
