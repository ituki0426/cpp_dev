#include <bitset>
#include <iostream>
using namespace std;
int main(void) {
    int a = 45;
    int b = 25;
    cout << a << ": " << bitset<8>(a) << endl;
    cout << b << ": " << bitset<8>(b) << endl;
    cout << a << " OR " << b << " = " << (a | b) << ": " << bitset<8>(a | b)
         << endl;
}