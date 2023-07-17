#include <iostream>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int small;
    int large;
    for (int i = 0; i < 5; i++) {
        if ((n + i) % 5 == 0) small = i;
    }
    for (int i = 4; i >= 0; i--) {
        if ((n - i) % 5 == 0) large = i;
    }
    if (small > large) {
        cout << n - large << endl;
    } else {
        cout << n + small << endl;
    }
}