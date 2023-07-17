#include <iostream>
#include <numeric>  // std::iota()
#include <utility>  // std::swap()
#include <vector>
using namespace std;
int main(void) {
    int N;
    int Q;
    cin >> N >> Q;
    int answer = N;
    vector<vector<int>> data(N, vector<int>(N, 0));
    while (Q--) {
        int q;
        int u, v;
        cin >> q;
        if (q == 1) {
            cin >> u >> v;
            u--;
            v--;
            data.at(u).push_back(v);
            data.at(v).push_back(u);
            answer -= 2;
        } else {
            int v;
            cin >> v;
            v--;
            for (const auto &i : data.at(v)) {
                for (const auto &j : data.at(i)) {
                    if (j == v) continue;
                    if (find(data.at(v).begin(), data.at(v).end(), j) ==
                        data.at(v).end()) {
                        data.at(v).push_back(j);
                        answer--;
                    }
                }
            }
        }
    }
}