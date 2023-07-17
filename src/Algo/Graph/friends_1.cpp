#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(void) {
    int N, A, B;
    cin >> N >> A >> B;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    if (S[A].at(B) == 'o')
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}