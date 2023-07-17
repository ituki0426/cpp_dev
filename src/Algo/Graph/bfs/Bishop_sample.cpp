// AtCoder ABC 246 E - Bishop 2 (水色, 500 点)
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1 << 29;
const vector<int> dx = {1, 1, -1, -1};
const vector<int> dy = {1, -1, 1, -1};
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
int main(void) {
    int N;
    int Ax, Ay, Bx, By;
    cin >> N >> Ax >> Ay >> Bx >> By;
    Ax--;
    Ay--;
    Bx--;
    By--;
    vector<string> field(N);
    rep(i, N) cin >> field[i];
    vector<vector<vector<int>>> dp(N,
                                   vector<vector<int>>(N, vector<int>(4, INF)));
    deque<tuple<int, int, int>> que;
    rep(dir, 4) {
        dp[Ax][Ay][dir] = 1;
        que.push_back(make_tuple(Ax, Ay, dir));
    }
    while (!que.empty()) {
        auto [x, y, dir] = que.front();
        que.pop_front();
        rep(ndir, 4) {
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (field[nx][ny] == '#') continue;

            int cost = (ndir != dir);
            if (chmin(dp[nx][ny][ndir], dp[x][y][dir] + cost)) {
                if (cost == 0)
                    que.push_front(make_tuple(nx, ny, ndir));
                else
                    que.push_back(make_tuple(nx, ny, ndir));
            }
        }
    }
    int res = INF;
    rep(dir, 4) chmin(res, dp[Bx][By][dir]);
    cout << (res < INF ? res : -1) << endl;
}