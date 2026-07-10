#include <iostream>
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
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sum = (sum + x % MOD + MOD) % MOD;
    }
    long long ans = (sum * modpow(2, n - 1)) % MOD;
    cout << ans << '\n';
    return 0;
}
