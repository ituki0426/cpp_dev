// 高速素因数分解
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Eratosthenes {
    vector<bool> isprime;
    // 整数iを割り切る最小の素数
    vector<int> minfactor;
    Eratosthenes(int N) : isprime(N + 1, true), minfactor(N + 1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;
        for (int p = 2; p <= N; ++p) {
            if (!isprime[p]) continue;
            minfactor[p] = p;
            for (int q = 2 * p; q <= N; q += p) {
                isprime[q] = false;
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }
};
int main(void) {}