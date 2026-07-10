#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1000000007LL;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<bool> danger(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        danger[x] = true;
    }
    vector<long long> dp(n + 1, 0), pref(n + 1, 0);
    dp[0] = 1;
    pref[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!danger[i]) {
            int left = max(0, i - k);
            long long sum = pref[i - 1];
            if (left > 0) sum = (sum - pref[left - 1] + MOD) % MOD;
            dp[i] = sum;
        } else {
            dp[i] = 0;
        }
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}
