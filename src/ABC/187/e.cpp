#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N;
    cin >> N;
    Graph G(N);
    vector<int> A(N - 1), B(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    int root = 0;
    vector<int> par(N, -1);
    vector<long long> add(N, 0);
    auto dfs = [&](auto self, int v, int p) -> void {
        par[v] = p;
        if (p != -1) add[v] += add[p];
        for (auto e : G[v]) {
            if (e == p) continue;
            self(self, e, v);
        }
    };
    dfs(dfs, root, -1);
    long long offset = 0;
    int Q;
    cin >> Q;
    while (Q--) {
        int type, id, v;
        cin >> type >> id >> v;
        id--;
        int a = A[id], b = B[id];
        if (type == 1) swap(a, b);
        if (par[a] == b) {
            add[a] += v;
        } else {
            add[b] -= v;
            offset += v;
        }
    }
    dfs(dfs, root, -1);
    for (int i = 0; i < N; i++) cout << add[i] + offset << endl;
}