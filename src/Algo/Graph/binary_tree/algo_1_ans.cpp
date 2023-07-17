#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
vector<int> number;
void rec(int v, vector<int>& L, vector<int>& R) {
    if (L[v] != -1) rec(L[v], L, R);
    number.push_back(v);
    if (R[v] != -1) rec(R[v], L, R);
    return;
}
int main(void) {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];
    rec(0, L, R);
    rep(i, N) { cout << number[i] << " "; }
    cout << endl;
}
