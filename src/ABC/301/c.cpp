#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    string S;
    string T;
    int dif_num = 0;
    vector<int> S_dic(150, 0);
    vector<int> T_dic(150, 0);
    cin >> S;
    cin >> T;
    int num_at_S = 0;
    int num_at_T = 0;
    for (const auto &c : S) {
        if (c == '@') {
            num_at_S++;
        } else {
            S_dic.at(int(c)) += 1;
        }
    }
    for (const auto &c : T) {
        if (c == '@') {
            num_at_T++;
        } else {
            T_dic.at(int(c)) += 1;
        }
    }
    for (int i = 0; i < 150; i++) {
        dif_num += abs(S_dic.at(i) - T_dic.at(i));
        if (i != int('a') && i != int('t') && i != int('c') && i != int('o') &&
            i != int('d') && i != int('e') && i != int('r') &&
            S_dic.at(i) - T_dic.at(i) != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (dif_num <= num_at_S + num_at_T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
