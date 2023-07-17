// 幅優先探索
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
using pint = pair<int, int>;
int main(void) {
    int R, C, sx, sy, tx, ty;
    cin >> R >> C >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    vector<string> field(R);
    queue<pint> que;
    Graph dist(R, vector<int>(C, -1));
    rep(i, R) cin >> field[i];
    que.push({sx, sy});
    dist[sx][sy] = 0;

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        rep(dir, 4) {
            int x2 = x + dx[dir];
            int y2 = y + dy[dir];

            // 場外の場合はダメ
            if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C) continue;

            // 壁の場合はダメ
            if (field[x2][y2] == '#') continue;

            // すでに探索済みの場合はダメ
            if (dist[x2][y2] != -1) continue;

            // それ以外はOK
            que.push({x2, y2});
            dist[x2][y2] = dist[x][y] + 1;
        }
    }
    cout << dist[tx][ty] << endl;
}