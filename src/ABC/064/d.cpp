#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string str;
    deque<char> deq;
    int N;
    cin >> N;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            deq.push_back('(');
        }
        if (str[i] == ')') {
            if (deq.empty()) {
                deq.push_back(')');
            } else {
                if (deq.back() == ')') deq.push_back(')');
                if (deq.back() == '(') deq.pop_back();
            }
        }
    }
    int num_l = 0;
    int num_r = 0;
    while (!deq.empty()) {
        if (deq.front() == '(') num_r++;
        if (deq.front() == ')') num_l++;
        deq.pop_front();
    }
    while (num_l--) cout << '(';
    cout << str;
    while (num_r--) cout << ')';
}