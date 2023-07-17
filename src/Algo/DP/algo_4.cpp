#include <iostream>
#include <vector>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<string>;
int main(void) {
    int N;
    cin >> N;
    Graph G(N);
    vector<vector<int>> dp(N, vector<int>(N, 0));
    rep(i, N) cin >> G[i];
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, N) {
            if(i + 1 < N && G[i+1][j] == '.') dp[i+1][j] += dp[i][j];
            if(j + 1 < N && G[i][j+1] == '.') dp[i][j+1] += dp[i][j];
        }
    }
    cout << G[N - 1][N - 1] << endl;
}