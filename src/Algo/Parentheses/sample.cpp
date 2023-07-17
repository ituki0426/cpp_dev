#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void) {
    string str;
    stack<char> st;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push('(');
        }
        if (str[i] == ')') {
            if (st.empty()) {
                st.push(')');
            } else {
                if (st.top() == ')') st.push(')');
                if (st.top() == '(') st.pop();
            }
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}