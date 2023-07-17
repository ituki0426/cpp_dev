// 1次元の座標圧縮
#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<T> compress(vector<T> &X) {
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(auto &e : X) {
        e = lower_bound(vals.begin(), vals.end(), e) - vals.begin();
    }
    return X;
}

int main(void) {
    vector<int> N = {1, 10, 5, 32, 99, 8, 10};
    for (const auto &e : compress(N)) {
        cout << e << " ";
    }
}