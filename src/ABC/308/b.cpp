#include <iostream>
#include <string>
#include <vector>
using ll = long long;
using namespace std;
int main(void) {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<string> c(N + 1);
    vector<string> d(M + 1);
    vector<int> p(M + 1);
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= M; i++) cin >> d[i];
    for (int i = 0; i <= M; i++) cin >> p[i];
    for (int i = 1; i <= N; i++) {
        auto result = find(d.begin(), d.end(), c[i]);
        if (result != d.end()) {
            ans += p[result - d.begin()];
        } else {
            ans += p[0];
        }
    }
    cout << ans << endl;
}