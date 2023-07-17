// 部活のスケジュール表
#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
const int MOD = 10007;
template <class T>
T add_mod(T &a, const T &b) {
    a += b;
    a %= MOD;
}
int N;
string S;
int dp[1 << 3][1100];
int resp[1100];  // resp[i]: i日目に誰が来たか？（J:1<<0, O:1<<1, I:1<<2）
int main(void) {
    cin >> N >> S;
    REP(i, N) {
        if (S[i] == 'J')
            resp[i + 1] = 1 << 0;
        else if (S[i] == 'O')
            resp[i + 1] = 1 << 1;
        else if (S[i] == 'I')
            resp[i + 1] = 1 << 2;
    }
    dp[1][0] = 1;
    REP(i, N) {
        REP(now, 1 << 3) {
            REP(next, 1 << 3) {
                // ２日連続で来れる人がいるか
                if (now & next) {
                    // 責任者が来た時のみ加算する
                    if (next & resp[i + 1]) {
                        add_mod(dp[next][i + 1], dp[now][i]);
                    }
                }
            }
        }
    }
    int ans = 0;
    REP(now, 1 << 3) add_mod(ans, dp[now][N]);
    cout << ans << endl;
    
}