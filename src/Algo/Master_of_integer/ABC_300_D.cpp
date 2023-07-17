#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
// エラトステネスの篩の実装
vector<bool> Era(int n) {
    vector<bool> isprime(n, true);
    isprime[0] = false;
    isprime[1] = false;
}
int main() {
    long long N;
    cin >> N;
    const int MAX = 1100000;
    vector<bool> isprime = Era(MAX);

    // 1以上r未満の個数を数えられるようにするための累積和
    vector<long long> S(MAX + 1, 0);
    for (int i = 0; i < MAX; i++) {
        S[i + 1] = S[i] + isprime[i];
    }
    long long res = 0;
    for (long long a = 1; a * a * a * a * a <= N; a++) {
        if (!isprime[a]) continue;
        for (long long b = a + 1; b * b * b <= N; b++) {
            // b+1以上、N/a^2b以下の素数の個数を足す
            long long cmax = sqrt(N / a / a / b);
            if (b + 1 <= cmax + 1) res += S[cmax + 1] - S[b + 1];
        }
    }
    cout << res << endl;
}