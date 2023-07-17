#include <iostream>
using namespace std;
int N, A[1000000], S[1000000];
int Q, L[1000000], R[1000000];

int main(void) {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) cin >> L[i] >> R[i];

    S[0] = 0;
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

    for (int j = 1; j <= N; j++) cout << S[j] << " ";

    cout << endl;
}