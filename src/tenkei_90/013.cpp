#include <iostream>
#include <queue>
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
void Dijkstra(const Graph& graph, vector<ll> distances, int startIndex) {
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
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<ll> distancesFrom1(N, INF);
    Dijkstra(graph, distancesFrom1, 0);

    vector<ll> distancesFromN(N, INF);
    Dijkstra(graph, distancesFromN, N - 1);

    for (int i = 0; i < N; i++) {
        cout << distancesFrom1[i] + distancesFromN[i] << endl;
    }
}