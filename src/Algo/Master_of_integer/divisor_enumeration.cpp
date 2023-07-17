// 約数列挙を行うプログラム
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<long long> enum_divisors(long long N) {
    set<long long> res;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.insert(i);
            res.insert(N / i);
        }
    }
    return res;
}
int main(void) {
    long long N;
    cin >> N;
    const auto &res = enum_divisors(N);
    for (const auto &e : res) {
        cout << e << " ";
    }
    cout << endl;
}