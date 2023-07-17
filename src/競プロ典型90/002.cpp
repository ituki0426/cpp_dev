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
        int sum_l = 0;
        int sum_r = 0;
        bool is_ok = true;
        string S;
        vector<int> ruiseki(N, 0);
        rep(i, N) {
            if (bit & (1 << i)) {
                if (i == 0)
                    ruiseki[i] = -1;
                else
                    ruiseki[i] = ruiseki[i - 1] - 1;
                S.push_back(')');
                sum_r++;
                if (ruiseki[i] < 0) is_ok = false;
            } else {
                if (i == 0)
                    ruiseki[i] = 1;
                else
                    ruiseki[i] = ruiseki[i - 1] + 1;
                S.push_back('(');
                sum_l++;
            }
        }
        if (is_ok && sum_l == sum_r) {
            ans.push_back(S);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto s : ans) cout << s << endl;
    cout << endl;
}
