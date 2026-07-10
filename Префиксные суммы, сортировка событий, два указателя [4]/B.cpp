#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    vector<int> L(n), R(n);
    stack<int> st;
 
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
 
    while (!st.empty()) st.pop();
 
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }
 
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * 1LL * (i - L[i]) * (R[i] - i);
    }
 
    cout << ans << '\n';
    return 0;
