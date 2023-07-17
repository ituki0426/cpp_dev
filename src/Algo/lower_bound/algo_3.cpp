// アルゴ式：最小の添字
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int N, M;
int main(void) {
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    rep(i, M) cout << lower_bound(A.begin(), A.end(), B[i]) - A.begin() << endl;
}