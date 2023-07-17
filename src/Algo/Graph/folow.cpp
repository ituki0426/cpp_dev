#include <iostream>
#include <set>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<multiset<int>> Graph(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        Graph[a].insert(b);
    }
    rep(i, N) {
        for (auto itr = Graph[i].begin(); itr != Graph[i].end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }
}