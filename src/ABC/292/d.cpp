#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    dsu D(N);
    for (int i = 0; i < M; i++) {
        D.merge(u[i], v[i]);
    }
    vector<int> vs(N, 0), es(N, 0);
    for (int i = 0; i < N; i++) {
        vs[D.leader(i)]++;
    }

    for (int i = 0; i < M; i++) {
        es[D.leader(u[i])]++;
    }
    if (vs == es)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}