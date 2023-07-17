#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;  // 0-indexed
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int v = 0; v < N; v++) {
        set<int> S;
        for (auto i : G[v])
            for (auto j : G[i]) S.insert(j);
        S.erase(v);
        for (auto i : G[v]) S.erase(i);
        cout << S.size() << endl;
    }
}