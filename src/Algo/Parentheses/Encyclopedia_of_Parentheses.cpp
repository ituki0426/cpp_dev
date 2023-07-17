// 競プロ典型 90 問 002 - Encyclopedia of Parentheses（★3）
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main(void) {
    vector<string> ans;
    int N;
    cin >> N;
    rep(bit, (1 << N)) {
        vector<int> ruiseki(N, 0);
        int sum_l = 0;
        int sum_r = 0;
        string str;
        bool is_ok = true;
        rep(i, N) {
            if (bit & (1 << i)) {
                if (i == 0)
                    ruiseki[i] = -1;
                else
                    ruiseki[i] = ruiseki[i - 1] - 1;
                str.push_back(')');
                sum_r++;
                if (ruiseki[i] < 0) is_ok = false;
            } else {
                if (i == 0)
                    ruiseki[i] = 1;
                else
                    ruiseki[i] = ruiseki[i - 1] + 1;
                str.push_back('(');
                sum_l++;
            }
        }
        if (is_ok && sum_l == sum_r) ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    for (auto s : ans) cout << s << endl;
}