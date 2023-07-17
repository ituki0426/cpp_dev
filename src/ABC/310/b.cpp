#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int M, N;
    cin >> N >> M;
    vector<vector<int> > G(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        int p;
        int c;
        cin >> p >> c;
        for (int j = 0; j < c; j++) cin >> G[i][j];
    }
    cout << endl;
}