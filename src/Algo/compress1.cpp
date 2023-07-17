// 座標圧縮
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    vector<int> A = {8, 100, 33, 33, 33, 12, 6, 1211};
    vector<int> B = A;
    sort(B.begin(), B.end());
    // 重複を削除
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<int> res(A.size());
    for (int i = 0; i < A.size(); i++) {
        res[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }
    for (const auto &e : res) {
        cout << e << " ";
    }
}