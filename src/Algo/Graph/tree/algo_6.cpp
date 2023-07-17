// アルゴ式:Q1. 箱の中の箱
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 1; i < N; i++) cin >> A[i];
    int res = 0;
    while (X != 0) {
        res++;
        X = A[X];
    }
    cout << res << endl;
}