#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class BIT {
   public:
    BIT() = default;
    explicit BIT(size_t size) : m_bit(size + 1, 0) {}
    explicit BIT(const vector<ll>& v) : BIT(v.size()) {}

    ll sum(int r) const {
        ll ret = 0;
        for (; 0 < r; r -= (r & -r)) {
            ret += m_bit[r];
        }
        return ret;
    }
    ll sum(int l, int r) const { return sum(r) - sum(l - 1); }
    void add(int i, ll value) {
        for (; i < m_bit.size(); i += (i & -i)) {
            m_bit[i] += value;
        }
    }

   private:
    vector<ll> m_bit;
};
int main(void) {
    int N, Q;
    cin >> N >> Q;
    BIT bit(N);
    while (Q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            bit.add(x, y);
        } else {
            cout << bit.sum(x, y) << endl;
        }
    }
}