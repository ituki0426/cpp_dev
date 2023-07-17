// 答えで二分探索
#include <iostream>
using namespace std;
using ll = long long;
ll N, K, A[100009];
bool isOk(ll x) {
    ll sum = 0;
    for (int i = 1; i <= N; i++) sum += x / A[i];
    if (sum >= K)
        return true;
    else
        return false;
}
int main(void) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    ll left = 0;
    ll right = 1e10;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (isOk(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
}
