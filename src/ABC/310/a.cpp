#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> D(N + 1);
    for (int i = 1; i <= N; i++) cin >> D[i];
    int min = *min_element(D.begin() + 1, D.end());
    if (min + Q < P)
        cout << min + Q << endl;
    else
        cout << P << endl;
}