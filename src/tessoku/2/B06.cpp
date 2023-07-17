#include <iostream>
using namespace std;
int main(void) {
    int N;
    int Q;
    cin >> N;
    int tmp;
    int A[N];
    int B[N];
    int atari[N + 1];
    int hazure[N + 1];
    atari[0] = 0;
    hazure[0] = 0;
    for (int j = 1; j <= N; j++) {
        cin >> tmp;
        if (tmp) {
            A[j] = 1;
            B[j] = 0;
        } else {
            A[j] = 0;
            B[j] = 1;
        }
    }
    cin >> Q;
    for (int j = 1; j <= N; j++) {
        atari[j] = atari[j - 1] + A[j];
        hazure[j] = hazure[j - 1] + B[j];
    }
    int L, R;
    int Ans[Q];
    for (int j = 0; j < Q; j++) {
        cin >> L >> R;
        if (atari[R] - atari[L - 1] > hazure[R] - hazure[L - 1])
            Ans[j] = 0;
        else if (atari[R] - atari[L - 1] == hazure[R] - hazure[L - 1])
            Ans[j] = 1;
        else
            Ans[j] = 2;
    }
    for (int j = 0; j < Q; j++) {
        if (Ans[j] == 0)
            cout << "win" << endl;
        else if (Ans[j] == 1)
            cout << "draw" << endl;
        else
            cout << "lose" << endl;
    }
}