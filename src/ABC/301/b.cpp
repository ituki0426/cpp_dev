#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> data(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < N; i++) {
        if (data[i + 1] > data[i] + 1 && i != N - 1) {
            cout << data[i] << " ";
            for (int j = 1; j < data[i + 1] - data[i]; j++) {
                cout << data[i] + j << " ";
            }
        } else if (data[i + 1] < data[i] - 1 && i != N - 1) {
            cout << data[i] << " ";
            for (int j = 1; j < data[i] - data[i + 1]; j++) {
                cout << data[i] - j << " ";
            }
        } else {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}