#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        while (r < n && a[r] - a[i] <= K) ++r;
        long long cnt = r - i - 1;
        if (cnt >= 2) ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
