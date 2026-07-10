#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long n;
    int k;
    cin >> n >> k;
    if (k == 0) {
        if (n % 2 == 1) cout << n << '\n';
        else cout << n - 1 << '\n';
        return 0;
    }
    long long p = 1LL << k;
    if (n < p) {
        cout << -1 << '\n';
        return 0;
    }
    long long x = n / p;
    if (x % 2 == 1) {
        cout << x * p << '\n';
    } else {
        cout << (x - 1) * p << '\n';
    }
    return 0;
}
