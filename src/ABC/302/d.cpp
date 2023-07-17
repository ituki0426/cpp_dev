#include <iostream>
#include <vector>
using namespace std;
struct data_type {
    int num;
    long long data;
    bool operator<(const data_type& another) const { return num < another.num; }
};
int main() {
    int N;
    int M;
    long long D;
    cin >> N >> M >> D;
    vector<data_type> data(N + M);
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> data.at(i).data;
        data.at(i).num = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> data.at(i + N).data;
        data.at(i + N).num = 1;
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < N + M; i++) {
        cout << data.at(i).num << " " << data.at(i).data << endl;
    }
}