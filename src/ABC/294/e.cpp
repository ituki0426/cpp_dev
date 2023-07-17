#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) if (A[N] % 2 == 0) cout << A[i] << " ";
    cout << endl;
}