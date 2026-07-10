#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    if (m > n) {
        cout << 0 << '\n' << '\n';
        return 0;
    }
    vector<int> freqB(101, 0), freqA(101, 0);
    for (int x : b) freqB[x]++;
    for (int i = 0; i < m; ++i) freqA[a[i]]++;
    int match = 0;
    for (int i = 1; i <= 100; ++i) if (freqA[i] == freqB[i]) match++;
    vector<int> ans;
    if (match == 100) ans.push_back(1);
    for (int l = 1; l <= n - m; ++l) {
        int rem = a[l - 1];
        int add = a[l + m - 1];
        if (freqA[rem] == freqB[rem]) match--;
        freqA[rem]--;
        if (freqA[rem] == freqB[rem]) match++;
        if (freqA[add] == freqB[add]) match--;
        freqA[add]++;
        if (freqA[add] == freqB[add]) match++;
        if (match == 100) ans.push_back(l + 1);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
