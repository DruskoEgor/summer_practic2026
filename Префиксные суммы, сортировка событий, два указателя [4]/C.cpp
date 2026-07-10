#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    long long cur = 0;
    long long minPrice = 0;
    int minIndex = 1;
 
    long long bestProfit = -4e18;
    int bestBuy = -1, bestSell = -1;
 
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        cur += x;
 
        long long profit = cur - minPrice;
 
        if (profit > bestProfit || (profit == bestProfit && minIndex < bestBuy)) {
            bestProfit = profit;
            bestBuy = minIndex;
            bestSell = i + 1;
        }
 
        if (cur < minPrice) {
            minPrice = cur;
            minIndex = i + 1;
        }
    }
 
    if (bestProfit <= 0) {
        cout << "-1 -1\n";
    } else {
        cout << bestBuy << ' ' << bestSell << '\n';
    }
 
    return 0;
}
