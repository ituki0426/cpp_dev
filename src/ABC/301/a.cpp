#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int N;
    string str;
    cin >> N;
    cin >> str;
    int half = N / 2;
    int S_win = 0;
    int T_win = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'T') {
            S_win++;
            if (S_win >= half) {
                cout << "T" << endl;
                return 0;
            }
        } else {
            T_win++;
            if (T_win >= half) {
                cout << "A" << endl;
                return 0;
            }
        }
    }
}
