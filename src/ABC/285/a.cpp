#include <iostream>
using namespace std;
int main(void) {
    int tmp;
    int a, b;
    cin >> a >> b;

    if (a < b) {
        tmp = b;
        b = a;
        a = tmp;
    }
    if (b * 2 == a || b * 2 + 1 == a) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}