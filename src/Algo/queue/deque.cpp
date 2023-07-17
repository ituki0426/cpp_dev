//
#include <iostream>
#include <queue>
using namespace std;
int main(void) {
    deque<int> deq;
    deq.push_front(3);
    deq.push_back(0);
    int f = deq.front();
    deq.pop_front();
    int b = deq.back();
    deq.pop_back();
}