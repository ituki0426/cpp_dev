#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, r, n) for (int i = r; i <= (n); ++i)
vector<bool> Eratosthenes(int N) {
    vector<bool> isprime(N + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    rep(p, 2, N) {
        if (!isprime[p]) continue;
        for (int q = p * 2; q <= N; q += p) isprime[q] = false;
    }
    return isprime;
}
int main(void) {
    vector<bool> isprime = Eratosthenes(50);
    rep(v, 2, 50) {
        cout << v << " : " << (isprime[v] ? "prime" : "not") << endl;
    }
}