#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    tuple<int, double, string> t1{1, 2.3, "aaa"};
    tuple<string, int, int> t2{"bbb", 4, 5};
    vector<tuple<string, int, int>> v = {{"ccc", 400, 500}, {"ddd", 600, 700}};
    
};
