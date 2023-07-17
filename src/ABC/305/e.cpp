#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M, K;
    cin >> N >> M >> K;
    vector<bool> answer();
    vector<pair<int, int>> gard(K);

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        gard[i] = make_pair(c, d);
    }
    for (int i = 0; i < K; i++) {
        int p, q;
        p = gard[i].first;
        q = gard[i].second;
    }
}

 B[0] = 0;
    for (int i = 1; i <= 10000000; i++) B[i] = B[i - 1] + A[i];
    while (Q--) {
        int tmp_l;
        int tmp_r;
        cin >> tmp_l >> tmp_r;
        Ans.push_back(B[tmp_r] - B[tmp_l - 1]);
    }
    for (int i = 0; i < Q; i++) {
        cout << Ans[i] << endl;
    }