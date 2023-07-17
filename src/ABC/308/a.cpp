#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    vector<int> a(8);
    for (int i = 0; i < 8; i++) {
        cin >> a[i];
        if (a[i] % 25 != 0) {
            cout << "No" << endl;
            return 0;
        }
        if (a[i] < 100 || a[i] > 675) {
            cout << "No" << endl;
            return 0;
        }
        if (i != 0 && a[i] < a[i - 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}