#include <bitset>
#include <iostream>
using namespace std;

const int INF = 100000000;  // 十分大きな値

/* 入力 */
int N;
int dist[21][21];
int dp[(1 << 20) + 1][21];

int rec(int bit, int v) {
    // すでに探索済みだったらリターン
    if (dp[bit][v] != -1) return dp[bit][v];
    // 初期値
    if (bit == (1 << v)) return dp[bit][v] = 0;
    int res = INF;
    // bit の v を除いたもの
    int prev_bit = bit & ~(1 << v);

    // v の手前のノードとして u を全探索
    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1 << u))) continue;  // u が prev_bit になかったらダメ
        if (res > rec(prev_bit, u) + dist[u][v]) {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }
    return dp[bit][v] = res;  // メモしながらリターン
}
int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }
    for (int bit = 0; bit < (1 << N); ++bit) {
        for (int v = 0; v < N; ++v) {
            dp[bit][v] = -1;
        }
    }

    // 探索
    int res = INF;
    for (int v = 0; v < N; ++v) {
        if (res > rec((1 << N) - 1, v)) {
            res = rec((1 << N) - 1, v);
        }
    }
    cout << res << endl;
}