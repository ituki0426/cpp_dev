#include <iostream>
#include <queue>
using ll = long long;
using namespace std;
int main(void) {
    queue<ll> que;
    deque<ll> deq;
    int Q;
    cin >> Q;
    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            deq.push_front(x);
        else if (t == 2)
            deq.push_back(x);
        else if (t == 3)
            que.push(deq.at(x - 1));
    }
    while (!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }
}