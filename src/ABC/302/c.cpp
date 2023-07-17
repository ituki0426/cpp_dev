#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    int n;
    int m;
    cin >> n >> m;
    vector<string> data(5);
    vector<int> num(26);
    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
        for (int j = 0; j < m; j++) {
            num.at(int(data.at(i).at(j)) - int('a'))++;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << num.at(i) << endl;
    }
}