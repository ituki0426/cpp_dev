#include <iostream>

using namespace std;
int main(void) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a == 3) {
        if (b == 2)
            cout << "Yes" << endl;
        else if (b == 6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (a == 6) {
        if (b == 3)
            cout << "Yes" << endl;
        else if (b == 9)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (a + 1 == b || a + 3 == b || a + 4 == b) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}