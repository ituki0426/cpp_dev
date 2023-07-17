#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main(void) {
    tuple<int, double, string> t{100, 1.1, "aaa"};
    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;
    get<1>(t) *= get<0>(t);
    cout << get<1>(t) << endl;
}