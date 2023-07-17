#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
tuple<int, double, string> MakeTuple() { return {1, 2.3, "aaa"}; }
int main(void){
    int a = 123;
    double b = 4.56;
    string c = "789";

    tie(a,b,c) = MakeTuple();
    cout << a << " " << b << " " << c << endl;
}