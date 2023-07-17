#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll min, max;
    rep(i, N) {
        if (i == 0) {
            min = A[i];
            max = A[i];
        }
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
    cout << abs(max - min) << endl;
}