#include <iostream>
#include <map>
#include <set>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<string, string> to;
    vector<string> s(n);
    vector<string> t(n);
    rep(i, n) cin >> s[i] >> t[i];
    rep(i, n) to[s[i]] = t[i];
    set<string> used;
    for (string ss : s) {
        string ns = ss;
        while (!used.count(ns)) {
            used.insert(ns);
            auto it = to.find(ns);
            if (it == to.end()) break;
            ns = it->second;
            if (ns == ss) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}