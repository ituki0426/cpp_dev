// いもす法の練習問題
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int main(void) {
    int N;
    cin >> N;
    int A = 1000001;
    vector<int> v(A + 1, 0);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    rep(i, A + 1) v[i + 1] += v[i];
    int res = 0;
    rep(i, A + 1) res = max(res, v[i]);
    cout << res << endl;
}