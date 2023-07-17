#include <algorithm>
#include <iostream>
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
int N, A[100009], dp[100009];
int LEN = 0, L[100009];
int main(void) {
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) {
        int pos = lower_bound(L, L + LEN + 1, A[i]) - L;
        dp[i] = pos;

        L[dp[i]] = A[i];
        if (dp[i] > LEN) LEN++;
    }
    cout << LEN << endl;
}