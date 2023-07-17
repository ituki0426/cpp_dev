// ビットDPの問題
#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1000000000
#define rep(i, r, n) for (int i = r; i < n; i++)
using namespace std;
int N, M;
int tmp;
vector<vector<int>> G;
vector<vector<int>> dp(100, vector<int>(1024, INF));
int main(void) {
    cin >> N >> M;
    rep(i, 0, M) {
        rep(j, 0, N) {
            cin >> tmp;
            G[i][j] = tmp;
        }
    }
    dp[0][0] = 0;
    rep(i, 1, M + 1) {
        rep(j, 0, (1 << N)) {
            
        }
    }
}
