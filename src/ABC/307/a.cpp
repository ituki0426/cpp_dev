#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
    int N, Q;
    cin >> N;
    vector<int> A(7 * N + 1);
    vector<int> B(N);
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 1; i <= 7 * N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= 7 * N; i++) {
        B[cnt] += A[i];
        cnt2++;
        if (cnt2 % 7 == 0) cnt++;
    }
    for (const auto& e : B) {
        cout << e << " ";
    }
}