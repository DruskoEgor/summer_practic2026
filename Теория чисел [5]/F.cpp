#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cnt(8, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (cnt[5] > 0 || cnt[7] > 0) {
        cout << -1 << '\n';
        return 0;
    }
    int need = n / 3;
    if (cnt[1] != need) {
        cout << -1 << '\n';
        return 0;
    }
    int x = cnt[4];
    int z = cnt[3];
    int y = cnt[2] - x;
    if (y < 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (cnt[6] != y + z) {
        cout << -1 << '\n';
        return 0;
    }
    if (x + y + z != need) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < x; ++i) cout << "1 2 4\n";
    for (int i = 0; i < y; ++i) cout << "1 2 6\n";
    for (int i = 0; i < z; ++i) cout << "1 3 6\n";
    return 0;
}
