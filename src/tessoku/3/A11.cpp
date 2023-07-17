#include <iostream>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
int N, X, A[100009];
int serch(int x) {
    int left = 0;
    int right = N;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
}

int main(void) {
    cin >> N;
    rep(i, N) cin >> A[i];
    cin >> X;
    cout << serch(X) << endl;
}