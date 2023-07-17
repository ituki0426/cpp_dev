// アルゴ式:Q2. グリッドグラフの連結性
#include <iostream>
using namespace std;
int main(void) {
    int H, W;
    cin >> H >> W;
    // N 頂点の木はちょうど (N−1) 本の辺を持つ
    cout << (W - 1) * H + (H - 1) * W - (H * W - 1) << endl;
}