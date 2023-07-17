#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(){};
template<class T> inline bool chmin(){};
const int MAX_N = 110;
const int MAX_V = 100100;
const ll INF = 1LL << 60;
int N, value[MAX_N];
ll W, wight[MAX_N], dp[MAX_N][MAX_V];
ll dp[MAX_N][MAX_V] = {INF};
int main(void) {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> wight[i] >> value[i];
}