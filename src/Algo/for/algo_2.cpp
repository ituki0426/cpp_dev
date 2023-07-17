#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll sum = 0;
    rep(i,N) sum += A[i];
    int m = *min_element(A.begin(),A.end());
    cout << sum - m << endl;
}