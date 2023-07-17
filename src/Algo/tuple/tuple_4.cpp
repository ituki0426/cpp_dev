#include <iostream>
using namespace std;
void Print(int a, double b, const string& c) {
    cout << a << " " << b << " " << c << endl;
}
int main(void) {
    tuple<int, double, string> t{1, 1.1, "aaa"};
    apply(Print, t);
}