#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int>>;
int main(void) {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int index = -1;
    int max = -1;
    rep(i, N) {
        if (max < (int)graph[i].size()) {
            max = (int)graph[i].size();
            index = i;
        }
    }
    sort(graph[index].begin(), graph[index].end());
    for (const auto v : graph[index]) cout << v << " ";
    cout << endl;
}