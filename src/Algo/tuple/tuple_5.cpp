#include <iostream>
#include <string>
#include <tuple>
using namespace std;
struct Person {
    int age;
    string name;
    bool operator<(const Person& other) const {
        return tie(name, age) < tie(other.name, other.age);
    }
    bool operator==(const Person& other) const {
        return tie(name, age) == tie(other.name, other.age);
    }
};
int main(void) {
    Person p1{10, "aaa"};
    Person p2{20, "bbb"};
    cout << boolalpha;
    cout << (p1 < p2) << endl;
    cout << (p1 == p2) << endl;
}