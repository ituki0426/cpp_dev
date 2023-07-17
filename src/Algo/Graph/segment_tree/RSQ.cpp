#include <algorithm>
#include <iostream>
using namespace std;
class SegmentTree {
   public:
    int dat[300000], siz = 1;
    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    }
    void update(int pos, int x) {
        pos += siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = dat[pos * 2] + dat[pos * 2 + 1];
        }
    }
    int query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, u * 2);
        int AnswerR = query(l, r, m, b, u * 2 + 1);
        return AnswerL + AnswerR;
    }
};
SegmentTree Z;
int N, Q;
int Query[100009], pos[100009], x[100009], l[100009], r[100009];
int main(void) {
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> Query[i];
        if (Query[i] == 1) cin >> x[i] >> pos[i];
        if (Query[i] == 2) cin >> l[i] >> r[i];
    }
    Z.init(N);
    for (int i = 1; i <= Q; i++) {
        if (Query[i] == 1) {
            Z.update(pos[i], x[i]);
        }
        if (Query[i] == 2) {
            int Answer = Z.query(l[i], r[i] + 1, 1, Z.siz + 1, 1);
            cout << Answer << endl;
        }
    }
}
