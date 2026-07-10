#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i<n; ++i){
        cin >> a[i];
    }
    
    int l, r;
    while (cin >> l >> r) {
        if (l == 0 && r == 0) break;
 
        --l;
        --r;
        
        while (l < r) {
            swap(a[l], a[r]);
            ++l;
            --r;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
 
    return 0;
}
