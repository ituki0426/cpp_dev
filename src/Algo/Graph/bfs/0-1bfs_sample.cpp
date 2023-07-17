#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int main(void) {
    int N;
    int s;
    vector<vector<pair<int, int>>> edges(N);
    vector<int> dist(N, INF);
    dist[s] = 0;
    deque<int> que;
    que.push_back(s);
    while (que.size()) {
        int i = que.front();
        que.pop_front();
        for (auto [j, c] : edges[i]) {
            int d = dist[i] + c;
            if (d < dist[j]) {
                dist[j] = d;
                if (c) {
                    que.push_back(j);
                } else {
                    que.push_front(j);
                }
            }
        }
    }
}