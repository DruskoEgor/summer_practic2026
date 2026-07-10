#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    vector<int> mn, mx;
    int gminPos = 0, gmaxPos = 0;
 
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[gminPos]) gminPos = i;
        if (a[i] > a[gmaxPos]) gmaxPos = i;
 
        bool isMin = false, isMax = false;
        if (i == 0) {
            if (n == 1) {
                isMin = isMax = true;
            } else {
                if (a[i] < a[i + 1]) isMin = true;
                else if (a[i] > a[i + 1]) isMax = true;
            }
        } else if (i == n - 1) {
            if (a[i] < a[i - 1]) isMin = true;
            else if (a[i] > a[i - 1]) isMax = true;
        } else {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) isMin = true;
            else if (a[i] > a[i - 1] && a[i] > a[i + 1]) isMax = true;
        }
 
        if (isMin) mn.push_back(i + 1);
        if (isMax) mx.push_back(i + 1);
    }
 
    cout << mn.size();
    for (int p : mn) cout << ' ' << p;
    cout << '\n';
 
    cout << mx.size();
    for (int p : mx) cout << ' ' << p;
    cout << '\n';
 
    cout << gminPos + 1 << ' ' << gmaxPos + 1 << '\n';
 
    return 0;
}
