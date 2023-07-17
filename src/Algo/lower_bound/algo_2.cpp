// アルゴ式：貯金(1)
#include <iostream>
using namespace std;
int N;
int M;
double low = 0;
double high = 10.0;
int isValid(double x) {
    double res = N + 1.0;
    for (int i = 1; i <= 5; i++) res = res * x + 1.0;
    if (res < M)
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
    cin >> N >> M;

    cout << binary_serch() << endl;
}
