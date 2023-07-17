// lower_boundの実装
#include <iostream>
#include <vector>
using namespace std;
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOk(int index, int key) {
    if (a[index] >= key)
        return true;
    else
        return false;
}
int binary_serch(int key) {
    int ng = -1;
    int ok = (int)a.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOk(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}
int main(void) {
    cout << binary_serch(51) << endl;
    cout << binary_serch(1) << endl;
    cout << binary_serch(910) << endl;
    cout << binary_serch(52) << endl;
    cout << binary_serch(0) << endl;
    cout << binary_serch(911) << endl;
}