#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<long long> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    sort(d.begin(), d.end());
    int q;
    cin >> q;
    while (q--) {
        long long s, f;
        cin >> s >> f;
        if (s > f) swap(s, f);
        int left = lower_bound(d.begin(), d.end(), s) - d.begin();
        int right = upper_bound(d.begin(), d.end(), f) - d.begin();
        cout << right - left << '\n';
    }
    return 0;
}
