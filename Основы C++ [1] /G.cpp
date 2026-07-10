#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long n, k;
    cin >> n >> k;
 
    long long sum = 0;
    long long d = 1;
    long long remaining = k;
 
    while (remaining > 0) {
        long long cnt = 4 * (n + d - 1);
        long long take = min(remaining, cnt);
        sum += take * d;
        remaining -= take;
        ++d;
    }
 
    cout << sum << '\n';
    return 0;
}
