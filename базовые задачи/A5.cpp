#include <iostream>
#include <string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    string s, t;
    cin >> s >> t;
 
    int count = 0;
 
    for (int i = 0; i <= n - m; ++i) {
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != t[j]) {
                match = false;
                break;
            }
        }
        if (match) ++count;
    }
 
    cout << count << '\n';
    return 0;
}
