#include <algorithm>
#include <iostream>
using namespace std;
class SegmentTree {
   public:
    int dat[300000],siz = 1;
    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    }
    // クエリ1に対する処理
    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }
    // クエリ2に対する処理
    // uは現在のセル番号、[a,b)はセル対応する半開区間、[l,r)は求めたい半開区間
    int query(int l, int r, int a, int b, int u) {
        if (r <= l || b <= r) return -1000000000;  // 一切含まれない場合
        if (l <= a && b <= r) return dat[u];  // 完全に含まれる場合
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, u * 2);
        int AnswerR = query(l, r, m, b, u * 2 + 1);
        return max(AnswerL, AnswerR);
    }
};
int N, Q;
int Query[100009], pos[100009], x[100009], l[100009], r[100009];
SegmentTree Z;
int main(void) {
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> Query[i];
        if (Query[i] == 1) cin >> pos[i] >> x[i];
        if (Query[i] == 2) cin >> l[i] >> r[i];
    }
    Z.init(N);
    for (int i = 1; i <= Q; i++) {
        if (Query[i] == 1) {
            Z.update(pos[i], x[i]);
        }
        if (Query[i] == 2) {
            int Answer = Z.query(l[i], r[i], 1, Z.siz, 1);
            cout << Answer << endl;
        }
    }
    return 0;
}