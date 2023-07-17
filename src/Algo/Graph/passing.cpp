#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
constexpr long long INF = (1LL << 60);
struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<long long, int>;
void Dijkstra(const Graph& graph, vector<long long>& distances,
              int startIndex) {
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
    int N;
    int M;
    cin >> N >> M;
    vector<long long> distancesFrom1(N, INF);
    vector<long long> distancesFromN(N, INF);
    Graph graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        --A;
        --B;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    Dijkstra(graph, distancesFrom1, 0);
    Dijkstra(graph, distancesFromN, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << distancesFrom1[i] + distancesFromN[i] << endl;
    }
}