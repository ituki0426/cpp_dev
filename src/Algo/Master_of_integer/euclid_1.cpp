// Euclid の互除法とは、二つの整数 a,bの最大公約数を求める
using ll = long long;
ll GCD(ll a, ll b) {
    if (b == a)
        return a;
    else
        return GCD(b, a % b);
}