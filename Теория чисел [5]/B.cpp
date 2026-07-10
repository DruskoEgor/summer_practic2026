#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n == 0) {
            cout << 10 << '\n';
            continue;
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        vector<int> digits;
        for (int d = 9; d >= 2; --d) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }
        if (n > 1) {
            cout << -1 << '\n';
            continue;
        }
        sort(digits.begin(), digits.end());
        long long ans = 0;
        for (int d : digits) ans = ans * 10 + d;
        cout << ans << '\n';
    }
    return 0;
}
