#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
vector<int> A(100009);
int N, X;
bool isOk(int index, int key) {
    if (A[index] == key)
        return true;
    else
        return false;
}

int binary_serch(int x) {
    int L = 0;
    int R = N;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (isOk(mid, x))
            return mid;
        else if (A[mid] < x)
            L = mid + 1;
        else
            R = mid - 1;
    }
}
int main(void) {
    cin >> N;
    rep(i, N) cin >> A[i];
    cin >> X;
    cout << binary_serch(X) << endl;
}