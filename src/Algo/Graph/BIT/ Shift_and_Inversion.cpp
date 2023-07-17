#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class BIT {
   public:
    BIT() = default;
    explicit BIT(size_t size) : m_bit(size + 1, 0) {}
    explicit BIT(const std::vector<long long>& v) : BIT(v.size()) {
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
    vector<long long> m_bit;
};
int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    BIT bit(N);
    ll ans = 0;
    for (const auto& a : A) {
        ans += bit.sum((a + 1), N);
        bit.add((a + 1), 1);
    }
    for (const auto& a : A) {
        cout << ans << endl;
        ans -= a;
        ans += N - a - 1;
    }
}