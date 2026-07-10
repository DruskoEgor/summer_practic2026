#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        unordered_map<long long, int> cnt;
        int l = 0, ans = 0;
        for (int r = 0; r < n; ++r) {
            cnt[a[r]]++;
            while (cnt[a[r]] > 1) {
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) cnt.erase(a[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
