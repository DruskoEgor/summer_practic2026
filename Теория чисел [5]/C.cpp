#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long fact = 1;
    for (int i = 1; i <= n - 1; ++i) fact = (fact * i) % MOD;
    long long ans = (fact * modpow(2, MOD - 2)) % MOD;
    cout << ans << '\n';
    return 0;
}
