// アルゴ式:Q2-4. 小さい数の個数
#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < M; i++) {
        int left = 0;
        int right = N;
        while (left != right) {
            int mid = (left + right) / 2;
            if (A[mid] > B[i])
                right = mid;
            else
                left = mid + 1;
        }
        int ans = left;
        cout << ans << endl;
    }
    return 0;
}