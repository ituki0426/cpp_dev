#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s;
    string ans;
    cin >> s;
    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            ans += s[i];
            ans += to_string(cnt);
            cnt = 1;
        }
    }
    cout << ans << endl;
}