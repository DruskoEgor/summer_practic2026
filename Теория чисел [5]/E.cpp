#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long long b1, q, n;
        cin >> b1 >> q >> n;
        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }
        b1 %= MOD;
        q %= MOD;
        if (q == 1) {
            cout << (b1 * (n % MOD)) % MOD << '\n';
            continue;
        }
        long long num = (modpow(q, n) - 1 + MOD) % MOD;
        long long den = (q - 1 + MOD) % MOD;
        long long inv_den = modpow(den, MOD - 2);
        long long ans = b1 * num % MOD * inv_den % MOD;
        cout << ans << '\n';
    }
    return 0;
}
