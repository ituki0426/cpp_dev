#include <bits/stdc++.h>
using namespace std;
struct MyPair {
    int x;
    string y;
    MyPair operator+(const MyPair &other) {
        MyPair ret;
        ret.x = x + other.x;
        ret.y = y + other.y;
        return ret;
    }
    void operator=(const MyPair &other) {
        cout << "operator= called" << endl;
        x = other.x;
        y = other.y;
    }
    bool operator<(const MyPair &other) const { return (x < other.x); }
};
int main(void) {
    MyPair a = {1, "hello"};
    MyPair b = {2, "world"};
    MyPair c = {3, "world"};
    MyPair d = a + b;
    vector<MyPair> v = {b, a, d, c};
    sort(v.begin(), v.end());
    for (const auto &e : v) {
        cout << e.x << " " << e.y << endl;
    }
}