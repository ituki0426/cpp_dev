#include <bits/stdc++.h>
using namespace std;
long long podpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(void) {
    long long N, M;
    cin >> N >> M;
    long long ans = podpow(10LL, N, M * M) / M ;
    cout << ans << endl;
}