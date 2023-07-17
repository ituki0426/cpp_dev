// アルゴ式:Q1. 表と数字 (1)
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;
int main(void) {
    vector<vector<int>> data(4, vector<int>(4, 0));
    REP(i, 4) cin >> data[0][i];
    REP(i, 3) {
        REP(j, 4) {
            if (j - 1 >= 0) data[i + 1][j - 1] += data[i][j];
            data[i + 1][j] += data[i][j];
            if (j + 1 <= 3) data[i + 1][j + 1] += data[i][j];
        }
    }
    cout << data[3][3];
}
