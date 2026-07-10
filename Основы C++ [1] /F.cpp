#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long intSum = 0, fracSum = 0;
    string s;
    while (cin >> s) {
        size_t pos = s.find('.');
        intSum += stoll(s.substr(0, pos));
        fracSum += stoll(s.substr(pos + 1));
    }
 
    intSum += fracSum / 1000000000000000LL;
    fracSum %= 1000000000000000LL;
 
    cout << intSum << '.';
    cout << setw(15) << setfill('0') << fracSum << '\n';
    return 0;
}
