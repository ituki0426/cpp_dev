#include <iostream>
#include <vector>
using namespace std;
template <class Abel>
struct BIT {
    Abel UNITY_SUM = 0;
    vector<Abel> dat;
    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}
    void init(int n) { dat.assign(n, UNITY_SUM); }
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1) dat[i] += x;
    }
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1) res += dat[i];
        return res;
    }
    inline Abel sum(int a, int b) { return sum(b) - sum(a); }
    void print() {
        for (int i = 0; i < (int)dat.size(); i++) cout << sum(i, i + 1) << ",";

        cout << endl;
    }
};

int main(void) {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        bit.add(i, a);
    }
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            long long p, x;
            cin >> p >> x;
            bit.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }
}