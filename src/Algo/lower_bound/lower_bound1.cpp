#include <iostream>
#include <vector>
using ll = long long;
using Graph = vector<vector<int>>;
using namespace std;
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
using namespace std;
int binary_serch(int key) {
    int left = 0;
    int right = (int)a.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            right = mid - 1;
        else if (a[mid] < key)
            left = mid + 1;
    }
    return -1;
}
int main(void) {
    cout << binary_serch(51) << endl;
    cout << binary_serch(1) << endl;
    cout << binary_serch(910) << endl;
    cout << binary_serch(52) << endl;
    cout << binary_serch(0) << endl;
    cout << binary_serch(911) << endl;
}