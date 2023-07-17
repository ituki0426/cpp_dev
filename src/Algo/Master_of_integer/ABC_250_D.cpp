#include <iostream>
#include <vector>
using namespace std;
vector<int> Era(int n) {
    vector<int> res;
    vector<bool> isprime(n, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i < n; i++) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = 2 * i; j < n; j += i) {
                isprime[j] = false;
            }
        }
    }
    return res;
}
int main(void) {
    long long N;
    cin >> N;
    vector<int> prs = Era(1000000);
    long long res = 0;
    for (long long q : prs) {
        long long pmax = min(q - 1, N / q / q / q);
        long long low = -1;
        long long high = prs.size();
        while (high - low > 1) {
            long long x = (low + high) / 2;
            if (prs[x] > pmax)
                high = x;
            else
                low = x;
        }
        res += high;
    }
    cout << res << endl;
}