#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    priority_queue<long long, vector<long long>, greater<long long>> pq;
 
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }
 
    for (int i = 0; i < n - 1; ++i) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        cout << a << ' ' << b << '\n';
        pq.push(a + b);
    }
 
    return 0;
}
