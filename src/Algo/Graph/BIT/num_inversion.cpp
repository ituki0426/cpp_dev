// Chokudai SpeedRun 001 J - 転倒数
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class BIT {
   public:
    BIT() = default;
    explicit BIT(size_t size) : m_bit(size + 1, 0) {}
    explicit BIT(const vector<ll>& v) : BIT(v.size()) {
        for (size_t i = 0; i < v.size(); i++) {
            add(i, v[i]);
        }
    }
    ll sum(int r) const {
        ll ret = 0;
        for (; 0 < r; r -= (r & -r)) {
            ret += m_bit[r];
        }
        return ret;
    }
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
    void add(int i, ll value) {
        for (; i < m_bit.size(); i += (i & -i)) {
            m_bit[i] += value;
        }
    }

   private:
    vector<ll> m_bit;
};
int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    BIT bit(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += bit.sum(A[i], N);
        bit.add(A[i], 1);
    }
    cout << ans << endl;
}