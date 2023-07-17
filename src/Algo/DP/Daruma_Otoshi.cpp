#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int N;
vector<int> w;
vector<vector<int>> dp;

// メモ化再帰
int rec(int l = 0, int r = N) {
    if ((r - 1) <= 1) return 0;
    if ((r - 1) == 2) {
        if (abs(w[l] - w[l + 1]) <= 1)
            return 2;
        else
            return 0;
    }
    int &ret = dp[l][r];
    if (ret != -1) return ret;

    if (abs(w[l] - w[r - 1]) <= 1 && rec(l + 1, r - 1) == (r - l - 2))
        chmax(ret, r - l);
    for (int i = l + 1; i <= r - 1; ++i) {
        chmax(ret, rec(l, i) + rec(i, r));
    }
    return ret;
}

int main(void){
    vector<int> ans;
    while(true){
        cin >> N;
        if(N == 0) break;
        w.resize(N);
        for(int i = 0; i < N; ++i) cin >> w[i];
        dp.assign(N + 2, vector<int>(N + 2, -1));
        ans.push_back(rec());
    }
    for(auto i : ans) cout << i << endl;
    return 0;
}