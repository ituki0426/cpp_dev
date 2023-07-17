#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
using Graph = vector<vector<int>>;
int main(void) {
    int N;
    cin >> N;
    Graph G(N);
    vector<int> deg(N, 0);
    vector<int> dic(N, 0);
    queue<int> que;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);  // 無向グラフ
        deg[a] += 1;
        deg[b] += 1;
    }

    que.push(0);

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : G[u]) {
            if (dic[v] == 0) {
                dic[v] = dic[u] + 1;
                if (deg[v] == 1) ans.push_back(dic[v] + 1);
                que.push(v);
            }
        }
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
}
