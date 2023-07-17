#include <iostream>
using namespace std;
int clac_digit(long long N) {
    int digit = 0;
    while (N) {
        N /= 10;
        digit++;
    }
    return digit;
}
int main(void) {
    long long N;
    cin >> N;
    int res = (1 << 29);
    for (long long A = 1; A * A <= N; A++) {
        if (N % A == 0) {
            long long B = N / A;
            int F = max(clac_digit(A), clac_digit(B));
            res = min(res, F);
        }
    }
    cout << res << endl;
}