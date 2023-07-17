#include <bitset>
#include <iostream>
using namespace std;
int main(void) {
    int a = 45;
    int b = 25;
    cout << a << " AND " << b << " = " << (a & b) << endl;
    cout << a << " OR " << b << " = " << (a | b) << endl;

    int A = 0x2d;
    int B = 0x19;
    cout << A << " AND " << B << " = " << (A & B) << endl;
    cout << bitset<8>(A) << " AND " << bitset<8>(B) << " = " << bitset<8>(A & B)
         << endl;
}