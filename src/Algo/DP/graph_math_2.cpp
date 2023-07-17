// アルゴ式:Q1. 表と数字 ()
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<vector<int>> data(N, vector<int>(N, 0));
    REP(i, N) cin >> data[0][i];
    REP(i, N - 1) {
        REP(j, N) {
            if (j - 1 >= 0)
                data[i + 1][j - 1] = (data[i + 1][j - 1] + data[i][j]) % 100;
            data[i + 1][j] = (data[i + 1][j] + data[i][j]) % 100;
            if (j + 1 <= N - 1)
                data[i + 1][j + 1] = (data[i + 1][j + 1] + data[i][j]) % 100;
        }
    }
    cout << data[N - 1][N - 1];
}
