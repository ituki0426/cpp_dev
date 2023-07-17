#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string str;
    deque<char> deq;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'S') {
            deq.push_back(str[i]);
        }
        if (str[i] == 'T') {
            if (deq.empty()) {
                deq.push_back('T');
            } else {
                if (deq.back() == 'T') {
                    deq.push_back('T');
                }
                if (deq.back() == 'S') {
                    deq.pop_back();
                }
            }
        }
    }
    int ans = 0;
    while (!deq.empty()) {
        ans++;
        deq.pop_front();
    }
    cout << ans << endl;
}