#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(void) {
    int H, W;
    cin >> H >> W;
    bool ans = false;
    vector<string> S(H+1);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<int>> dist(H+1, vector<int>(W+1, -1));
    queue<pair<int, int>> que;
    if (S[0][0] == 's' || S[0][0] == 'n' || S[0][0] == 'u' || S[0][0] == 'k' || S[0][0] == 'e') {
        que.push(make_pair(0, 0));
        dist[0][0] = 1;
    }
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int x2 = x + dx[dir];
            int y2 = y + dy[dir];
            if (x2 >= 0 && x2 < W && y2 >= 0 && y2 < W) {
                if (S[x][y] == 's' && S[x2][y2] == 'n' && dist[x2][y2] == -1) {
                    que.push(make_pair(x2, y2));
                    dist[x2][y2] =  1;
                }
                if (S[x][y] == 'n' && S[x2][y2] == 'u' && dist[x2][y2] == -1) {
                    que.push(make_pair(x2, y2));
                    dist[x2][y2] = 1;
                }
                if (S[x][y] == 'u' && S[x2][y2] == 'k' && dist[x2][y2] == -1) {
                    que.push(make_pair(x2, y2));
                    dist[x2][y2] = 1;
                }
                if (S[x][y] == 'k' && S[x2][y2] == 'e' && dist[x2][y2] == -1) {
                    que.push(make_pair(x2, y2));
                    dist[x2][y2] = 1;
                }
                if (S[x][y] == 'e' && S[x2][y2] == 's' && dist[x2][y2] == -1) {
                    que.push(make_pair(x2, y2));
                    dist[x2][y2] = 1;
                }
            }
        }
    }

    if (dist[H - 1][W - 1] != -1) ans = true;
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}