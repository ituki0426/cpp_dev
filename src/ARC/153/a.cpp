#include <iostream>
#include <map>
const char s[] = {'A', 'B', 'C', 'D', 'E', 'F'};
using namespace std;
int main(void) {
    int N;
    cin >> N;
    N = (N - 1) + 100000;
    int num = 5;
    map<char, int> ans;
    while (N > 0) {
        ans[s[num]] = N % 10;
        N /= 10;
        num--;
    }
    cout << ans['A'] << ans['A'] << ans['B'] << ans['C'] << ans['D'] << ans['D']
         << ans['E'] << ans['F'] << ans['E'] << endl;
}