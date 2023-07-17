// ABC 272 E - Add and Mex
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(m);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        a += i;
        // 0 <= a + ix < n;
        int l = (0 <= a) ? 0 : ((-a + i - 1) / i);
        int r = (n <= a) ? 0 : ((-(a - n) + i - 1) / i);
        r = min(r, m);
        for (int j = l; j < r; j++) d[j].push_back(a + i * j);
    }
    for (int mi = 0; mi < m; mi++) {
        auto& b = d[mi];
        int sz = b.size();
        vector<bool> e(sz + 1);
        for (int i : b)
            if (i <= sz) e[i] = true;
        int ans = 0;
        while (e[ans]) ans++;
        cout << ans << endl;
    }
    return 0;
}