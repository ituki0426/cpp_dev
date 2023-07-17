// AtCoder ARC 005 C - 器物損壊！高橋君 (0-1 BFS) (水色)
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using Node = pair<int, int>;
const int INF = 1 << 29;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
int main(void) {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) cin >> field[i];

    int sx = -1;
    int sy = -1;
    int gx = -1;
    int gy = -1;
    rep(i, H) rep(j, W) {
        if (field[i][j] == 's') {
            sx = i;
            sy = j;
        }
        if (field[i][j] == 'g') {
            gx = i;
            gy = j;
        }
    }
    deque<Node> que;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    que.push_front(Node(sx, sy));
    dist[sx][sy] = 0;
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop_front();
        rep(dir, 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (field[nx][ny] != '#') {
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    que.push_front(Node(nx, ny));
                }
            } else {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push_back(Node(nx, ny));
                }
            }
        }
    }
    if (dist[gx][gy] <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;                                                                                           
}
