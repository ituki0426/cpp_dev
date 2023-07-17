// ABC 035 D – トレジャーハント
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using Pair = pair<ll, ll>;
const ll INF = 1LL << 60;
struct Edge {
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
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
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    Graph graph1(N), graph2(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph1[a].push_back({b, c});
        graph2[b].push_back({a, c});
    }
    vector<ll> distances1(N, INF);
    Dijkstra(graph1, distances1, 0);

    vector<ll> distances2(N, INF);
    Dijkstra(graph2, distances2, 0);

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        const ll t1 = distances1[i];
        const ll t2 = distances2[i];
        if (t1 == INF || t2 == INF) continue;
        const ll huntTime = T - (t1 + t2);
        ans = max(ans, huntTime * A[i]);
    }
    cout << ans << endl;
}