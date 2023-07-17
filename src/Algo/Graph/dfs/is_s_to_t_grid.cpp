#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int H, W;
vector<string> field;
bool seen[510][510];
void dfs(int h, int w) {
    seen[h][w] = true;
    rep (dir, 4) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;
        if (seen[nh][nw]) continue;
        dfs(nh, nw);
    }
}

int main(void) {
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; h++) cin >> field[h];
    int sh, sw, gh, gw;
    rep(h, H) {
        rep(w, W) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 'g') gh = h, gw = w;
        }
    }
    memset(seen, false, sizeof(seen));  // seen配列全体をfalseに初期化

    dfs(sh, sw);
    if (seen[gh][gw])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}