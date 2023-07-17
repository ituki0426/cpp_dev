#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const ll INF = 1 << 60;
struct SegementTree {
    int n;
    vector<ll> node;

   public:
    SegementTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;  // n..最下段の横幅
        node.resize(2*n-1,INF);
    }
};