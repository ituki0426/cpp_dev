#include <iostream>
#include <numeric>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll S = accumulate(A.begin(), A.end(), 0LL);
    cout << S * S << endl;
}