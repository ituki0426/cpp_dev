#include <functional>
#include <iostream>
#include <tuple>
using namespace std;
int main(void) {
    auto f = make_tuple(1, 'a', "foo");
    cout << get<0>(f) << endl;
    cout << get<1>(f) << endl;
    cout << get<2>(f) << endl;
    return 0;
}
