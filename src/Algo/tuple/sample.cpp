#include <bits/stdc++.h>
using namespace std;
int main(void) {
    tuple<int, string, bool> data(1, "hello", true);
    get<2>(data) = false;
    cout << get<0>(data) << endl;

    data = make_tuple(2, "world", true);

    int a;
    string b;
    bool c;
    tie(a, b, c) = data;
    cout << a << " " << b << " " << c << endl;
}