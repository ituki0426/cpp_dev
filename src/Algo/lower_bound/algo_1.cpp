// アルゴ式：方程式を解く
#include <iostream>
using namespace std;
int N;
double low = 0;
double high = 50.0;
int isValid(double x) {
    if (x * (x * (x + 1) + 2) + 3 < N)
        return 1;
    else
        return 0;
}
double binary_serch() {
    double mid;
    for (int loop = 0; loop < 100; loop++) {
        mid = (low + high) / 2.0;
        if (isValid(mid))
            low = mid;
        else
            high = mid;
    }
    return mid;
}
int main(void) {
    cin >> N;
    cout << binary_serch() << endl;
    return 0;
}