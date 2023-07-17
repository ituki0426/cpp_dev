// メビウス関数値の列挙
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct Eratosthenes {
    // テーブル
    vector<bool> is_prime;
    vector<int> min_factor;
    // メビウス関数値
    vector<int> mobius;
    Eratosthenes(int N)
        : is_prime(N + 1, true), min_factor(N + 1, -1), mobius(N + 1, 1) {
        is_prime[0] = is_prime[1] = false;
        min_factor[0] = 0;
        min_factor[1] = 1;
    }
};