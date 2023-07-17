#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using Node = pair<int, int>;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main(void) {
    vector<string> field(10);
    rep(i, 10) cin >> field[i];
    rep(px, 10) rep(py, 10) {
        queue<Node> que;
        vector<vector<int>> dist(10, vector<int>(10, -1));
        que.push(Node(px, py));
        dist[px][py] = 0;
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            rep(dir, 4) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
                if (field[nx][ny] == 'o') {
                    que.push(Node(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        bool ok = true;
        rep(i, 10) rep(j, 10) {
            if (field[i][j] == 'o' && dist[i][j] == -1) ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}