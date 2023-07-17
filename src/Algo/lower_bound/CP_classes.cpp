
#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
int main(void) {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    cin >> Q;
    while (Q--) {
        ll B;
        cin >> B;
        int j = lower_bound(A.begin(), A.end(), B) - A.begin();
        ll res = INF;
        if (j < N) res = min(res, A[j] - B);
        if (j > 0) res = min(res, B - A[j - 1]);

        cout << res << endl;
    }
}