#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(void) {
    string str;
    cin >> str;
    queue<char> que;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'S') {
            que.push(str[i]);
        }
        if (str[i] == 'T') {
            if (que.back() == 'T') {
            }
            if (que.back() == 'S') {
               
            }
        }
    }
}