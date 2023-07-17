#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep (i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
const ll INF = 1LL << 60;
int main(void) {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<vector<vector<ll> > > dp(
        N, vector<vector<ll> >(M, vector<ll>(2 * N + 2 * M - 4 + 1, INF)));
    dp[0][0][N + M - 2] = 0;
    vector<pair<int, int> > magic(K);
    vector<int> C(K);
    vector<int> D(K);
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        magic[i].first = a;
        magic[i].second = b;
        C[i] = c;
        D[i] = d;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pair<int, int> p = make_pair(i, j);
            if (find(magic.begin(), magic.end(), p) != magic.end()) {
                // このマスに魔法がある
                const int index =
                    find(magic.begin(), magic.end(), p) - magic.begin();
                const int c = C[index];
                const int d = D[index];
                for (int t = 0; t < 2 * (M + N - 2) + 1; t++) {
                    if (dp[i][j][t] != INF) {
                        t -= c;
                        while (t >= 0) {
                            dp[i][j][t] = dp[i][j][t + c] + d;
                            t -= c;
                        }
                    }
                }
            } else {
                // このマスに魔法がない
                for (int t = 0; t < 2 * (M + N - 2) + 1; t++) {
                    if (dp[i][j][t] != INF) {
                        for (int m = 0; m < 4; m++) {
                            const int x2 = i + dx[m];
                            const int y2 = j + dy[m];
                            if (x2 < 0 || y2 < 0 || x2 >= M || y2 >= N)
                                continue;
                            if (dp[i][j][t] < dp[i][j][t + 1])
                                dp[i][j][t + 1] = dp[i][j][t];
                        }
                    }
                }
            }
        }
    }
    cout << dp[0][0][2 * N + 2 * M - 4] << endl;
}
