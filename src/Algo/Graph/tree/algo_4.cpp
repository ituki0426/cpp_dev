// アルゴ式:Q4. 木の直径 (2)
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
int main(void) {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);  // 無向グラフ
    }
    vector<int> dic_s(N, 0);
    queue<int> que_s;
    que_s.push(0);
    int max = 0;
    while (!que_s.empty()) {
        int u = que_s.front();
        que_s.pop();
        for (auto v : G[u]) {
            if (dic_s[v] == 0) {
                dic_s[v] = dic_s[u] + 1;
                if (dic_s[v] > dic_s[max]) max = v;
                que_s.push(v);
            }
        }
    }
    queue<int> que_t;
    vector<int> dic_t(N, 0);
    que_t.push(max);
    while (!que_t.empty()) {
        int u = que_t.front();
        que_t.pop();
        for (auto v : G[u]) {
            if (dic_t[v] == 0) {
                dic_t[v] = dic_t[u] + 1;
                que_t.push(v);
            }
        }
    }
    cout << *max_element(dic_t.begin(), dic_t.end()) << endl;
}
