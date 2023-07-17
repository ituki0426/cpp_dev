#include <iostream>
#include <vector>
int MAX = 2100000;
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<long long> v(MAX, 0);
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        v[a]++;
    }
    //エラトステネスの篩
    for (int d = 1; d < MAX; ++d) {
        if (v[d] == 0) continue;
        if (v[d] > 1) v[d] = 0;
        // d の倍数を除去していく
        for (int e = d * 2; e < MAX; e += d) {
            v[e] = 0;
        }
    }
    long long res = 0;
    for (int d = 1; d < MAX; ++d) res += v[d];
    cout << res << endl;
}