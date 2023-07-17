// エラトステネスの篩の実装
#include <iostream>
#include <vector>
using namespace std;
// 1以上N以下の整数が素数かどうかを判定する配列を返す
vector<bool> Eras(int N) {
    vector<bool> isprime(N + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int p = 2; p <= N; p++) {
        if (!isprime[p]) continue;
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    return isprime;
}
int main(void) {
    vector<bool> isprime = Eras(50);
    for (int v = 2; v <= 50; v++) {
        cout << v << " " << (isprime[v] ? "prime" : "not") << endl;
    }
}