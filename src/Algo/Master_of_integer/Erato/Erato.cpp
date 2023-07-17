#include <iostream>
#include <vector>
using namespace std;
vector<bool> Erato(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p <= N; p++) {
        if (!is_prime[p]) continue;
        for (int q = p * 2; q <= N; q += p) {
            is_prime[q] = false;
        }
    }
    return is_prime;
}

int main(void) {
    vector<bool> is_prime = Erato(100);
    for (int v = 2; v <= 100; v++) {
            cout << v << ": " << (is_prime[v] ? "true" : "false") << endl;
    }
}
