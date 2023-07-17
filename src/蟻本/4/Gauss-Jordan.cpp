#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
typedef vector<double> vec;
typedef vector<vec> mat;
const double EPS = 1e-8;

vec gauss_jordan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + 1));
    rep(i, n) rep(j, n) B[i][j] = A[i][j];
    rep(i, n) B[i][n] = b[i];
    rep(i, n) {
        // 注目している変数の係数の絶対値が大きい式をi番目に持ってくる
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        }
        swap(B[i], B[pivot]);
        // 解がないか一意でない
        if (abs(B[i][i]) < EPS) return vec();

        // 注目している変数の係数を1にする
        for (int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // j番目の式からi番目の変数を消去
                for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
            }
        }
    }
    vec x(n);
    for (int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}
int main(void) {
    int n;
    cin >> n;
    mat A(n, vec(n));
    vec b(n);
    rep(i, n) rep(j, n) cin >> A[i][j];
    rep(i, n) cin >> b[i];
    vec x = gauss_jordan(A, b);
    rep(i, n) cout << x[i] << endl;
    return 0;
}