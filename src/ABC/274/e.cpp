#include <bits/stdc++.h>
#define bit(x, i) (((x) >> (i)) & 1)
#define rep (i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
// Geometry
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a - b) < eps; }

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
    double x, y;
    V(double x = 0, double y = 0) : x(x), y(y) {}
    V& operator+=(const V& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    V operator+(const V& v) const { return V(*this) += v; }
    V& operator-=(const V& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    V operator-(const V& v) const { return V(*this) -= v; }
    V& operator*=(double s) {
        x *= s;
        y *= s;
        return *this;
    }
    V operator*(double s) const { return V(*this) *= s; }
    V& operator/=(double s) {
        x /= s;
        y /= s;
        return *this;
    }
    V operator/(double s) const { return V(*this) /= s; }
    double dot(const V& v) const { return x * v.x + y * v.y; }
    double cross(const V& v) const { return x * v.y - v.x * y; }
    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    V normalize() const { return *this / norm(); }
    V rotate90() const { return V(y, -x); }
    int ort() const {  // orthant
        if (abs(x) < eps && abs(y) < eps) return 0;
        if (y > 0)
            return x > 0 ? 1 : 2;
        else
            return x > 0 ? 4 : 3;
    }
    bool operator<(const V& v) const {
        int o = ort(), vo = v.ort();
        if (o != vo) return o < vo;
        return cross(v) > 0;
    }
};
istream& operator>>(istream& is, V& v) {
    is >> v.x >> v.y;
    return is;
}
ostream& operator<<(ostream& os, const V& v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
}
void chmin(double& a, double b) { a = min(a, b); }
int main(void) {
    int n, m;
    cin >> n >> m;
    int w = m + n + 1;
    vector<V> p(w);
    for (int i = 0; i < w - 1; i++) cin >> p[i];
    int w2 = 1 << w;
    vector<double> sp(w2, 1);
    for (int s = 0; s < w2; s++) {
        for (int i = 0; i < m; i++)
            if (s >> (n + i) & 1) sp[s] /= 2;
    }
    vector dist(w, vector<double>(w));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) dist[i][j] = (p[i] - p[j]).norm();
    }
    const double inf = 1e18;
    vector dp(w2, vector<double>(w, inf));
    dp[0][n + m] = 0;
    for (int s = 0; s < w2; s++) {
        for (int v = 0; v < w; v++) {
            if (dp[s][v] == inf) continue;
            for (int u = 0; u < w; u++) {
                if (~s >> u & 1)
                    chmin(dp[s | 1 << u][u], dp[s][v] + dist[v][u] * sp[s]);
            }
        }
    }
    int t = (1 << n) - 1 | 1 << n + m;
    double ans = inf;
    for (int s = 0; s < w2; s++)
        if ((s & t) == t) chmin(ans, dp[s][n + m]);
    printf("%.10f\n", ans);
    return 0;
}