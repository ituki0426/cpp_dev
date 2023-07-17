#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

uintmax_t combination(unsigned int n, unsigned int r) {
    if (r * 2 > n) r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor = 1;
    for (unsigned int i = 1; i <= r; ++i) {
        dividend *= (n - i + 1);
        divisor *= i;
    }
    return dividend / divisor;
}

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    K = K - N
}
