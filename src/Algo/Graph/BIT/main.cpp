#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class BIT {
   public:
    BIT() = default;
    explicit BIT(size_t size) : m_bit(size + 1) {}
    explicit BIT(const vector<ll>& v) : BIT(v.size()) {
        for (int i = 0; i < v.size(); i++) add((i + 1), v[i]);
    }
    // 閉区間[1,r]の合計を返す
    ll sum(int r) const {
        ll ret = 0;
        for (; 0 < r; r -= r & -r) ret += m_bit[r];
        return ret;
    }
    ll sum(int l, int r) const { return sum(r) - sum(l - 1); }
    //数列のi番目の要素を加算
    void add(int i, ll value) {
        for (; i < m_bit.size(); i += i & -i) m_bit[i] += value;
    }

   private:
    vector<int> m_bit;
};
int main(void) {}