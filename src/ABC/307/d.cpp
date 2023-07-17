#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> ruiseki(N, 0);
    int cnt_r = 0;
    int cnt_l = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            cnt_l++;
            if (i == 0)
                ruiseki[i] = 1;
            else
                ruiseki[i] = ruiseki[i - 1] + 1;
        } else if (S[i] == ')') {
            cnt_r++;
            if (i == 0)
                ruiseki[i] = -1;
            else
                ruiseki[i] = ruiseki[i - 1] - 1;
        } else {
            if (i == 0)
                ruiseki[i] = 0;
            else
                ruiseki[i] = ruiseki[i - 1];
        }
    }
    int cnt = min(cnt_r, cnt_l);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == '(') {
                int ans = ruiseki[j] - 1;
                for (int t = j + 1; t < S.size(); t++) {
                    if (ruiseki[t] == ans && S[t] == ')') {
                        S.erase(j, t - j + 1);
                        break;
                        
                    }
                }
            }
        }
    }
    cout << S << endl;
}