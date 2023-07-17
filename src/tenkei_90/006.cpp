// 辞書順最小なものを求めるとき、しばしば貪欲法が有効ですね！
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
vector<vector<int>> calc_next(const string &S) {
    int N = (int)S.size();
    vector<vector<int>> res(N + 1, vector<int>(26, N));
    // 後ろから見る
    for (int i = N - 1; i >= 0; --i) {
        res[i] = res[i + 1];
        res[i][S[i] - 'a'] = i;
    }
    return res;
}
int main(void) {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    string res = "";
    auto nex = calc_next(S);
    // 貪欲法
    int j = -1;
    for (int i = 0; i < K; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            int k = nex[j + 1][c - 'a'];
            if (N - k >= K - i) {
                res += c;
                j = k;
                break;
            }
        }
    }
    cout << res << endl;
}
