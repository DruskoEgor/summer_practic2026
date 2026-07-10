#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            long long sum = a[i] + a[j];
            int pos = lower_bound(a.begin() + j + 1, a.end(), sum) - a.begin();
            ans += pos - (j + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
