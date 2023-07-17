#include <iostream>
using namespace std;
int main(void) {
    int num[1000000];
    num['A'] = 0;
    num['B'] = 3;
    num['C'] = 4;
    num['D'] = 8;
    num['E'] = 9;
    num['F'] = 14;
    num['G'] = 23;
    char p;
    char q;
    cin >> p >> q;
    cout << abs(num[p] - num[q]) << endl;
}
