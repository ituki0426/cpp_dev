#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int m = *min_element(A.begin(), A.end());
    int M = *max_element(A.begin(), A.end());
    cout << M - m << endl;
}