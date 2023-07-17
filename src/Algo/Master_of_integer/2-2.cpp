// 素数判定を行う
#include <iostream>
using namespace std;
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(void) {
    long long N;
    cin >> N;
    if (is_prime(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}