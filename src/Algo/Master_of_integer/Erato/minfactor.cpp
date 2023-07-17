#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct Eratosthenes {
    vector<bool> is_prime;
    vector<int> min_factor;
    Eratosthenes(int N) : is_prime(N + 1, true), min_factor(N + 1, -1) {
        is_prime[0] = false;
        is_prime[1] = false;
        min_factor[0] = 0;
        min_factor[1] = 1;
        for (int p = 2; p <= N; ++p) {
            if (!is_prime[p]) continue;
            min_factor[p] = p;
            for (int q = p * 2; q <= N; q += p) {
                is_prime[q] = false;
                if (min_factor[q] == -1) min_factor[q] = p;
            }
        }
    }
    vector<pair<int, int> > factorize(int n) {
        vector<pair<int, int> > res;
        while (n > 1) {
            int p = min_factor[n];
            int exp = 0;
            while (min_factor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }
};
int main(void) {
    Eratosthenes er(50);
    for (int n = 2; n <= 50; n++) {
        auto pf = er.factorize(n);
        cout << n << ": ";
        for (int i = 0; i < pf.size(); i++) {
            cout << pf[i].first << "^" << pf[i].second << " ";
        }
        cout << endl;
    }
}