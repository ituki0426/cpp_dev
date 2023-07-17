#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int N;
    string str;
    cin >> N;
    cin >> str;
    deque<char> deq1;  // 英小文字も含む
    deque<char> deq2;  // 英小文字は含まない
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            deq1.push_back('(');
            deq2.push_back('(');
        } else if (str[i] == ')') {
            if (deq2.empty()) {
                deq1.push_back(')');
                deq2.push_back(')');
            }else if (deq2.back() == '(') {
                while (deq1.back() != '(') {
                    deq1.pop_back();
                }
                deq1.pop_back();
                deq2.pop_back();
            } else {
                deq1.push_back(')');
                deq2.push_back(')');
            }
        } else {
            deq1.push_back(str[i]);
        }
    }
    while (!deq1.empty()) {
        cout << deq1.front();
        deq1.pop_front();
    }
    cout << endl;
}