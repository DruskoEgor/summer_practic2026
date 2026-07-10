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
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    int n = s.size();
    vector<long long> fact(n + 1), inv_fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    long long ans = fact[n];
    for (int i = 0; i < 26; i++) if (cnt[i] > 0) ans = ans * inv_fact[cnt[i]] % MOD;
    cout << ans << '\n';
    return 0;
}
