// 素因数分解
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back(make_pair(a, ex));
    }
    if (N != 1) res.push_back(make_pair(N, 1));
    return res;
}

int main(void) {
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;   
}