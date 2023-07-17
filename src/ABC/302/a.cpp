#include <iostream>
using namespace std;
int main(void) {
    long long a;
    long long b;
    long long answer = 0;
    cin >> a;
    cin >> b;
    if (a % b != 0) {
        cout << (long long int)(a / b) + 1 << endl;
    } else {
        cout << a / b << endl;
    }
}