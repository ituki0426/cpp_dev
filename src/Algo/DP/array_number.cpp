#include <iostream>
using namespace std;
int N, X, Y, A[109];
int main(void) {
    cin >> N >> X >> Y;
    A[0] = X;
    A[1] = Y;
    for (int i = 2; i < N; i++) A[i] = (A[i - 1] + A[i - 2]) % 100;
    cout << A[N - 1] << endl;
}