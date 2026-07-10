#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<long long>> a(n, vector<long long>(m));
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
 
    cout << m << ' ' << n << '\n';
 
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
 
    return 0;
}
