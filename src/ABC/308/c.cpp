#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<pair<float, int>> v(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[i].first = a / (a + b);
        v[i].second = i + 1;
    }
    
    for (auto V : v) {
        cout << V.first << " ";
    }
    cout << endl;
}