#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
 
    int minX1 = min(x1, x2), maxX1 = max(x1, x2);
    int minY1 = min(y1, y2), maxY1 = max(y1, y2);
    int minX2 = min(x3, x4), maxX2 = max(x3, x4);
    int minY2 = min(y3, y4), maxY2 = max(y3, y4);
 
    long long area1 = 1LL * (maxX1 - minX1) * (maxY1 - minY1);
    long long area2 = 1LL * (maxX2 - minX2) * (maxY2 - minY2);
 
    long long interX = 0, interY = 0;
    int left = max(minX1, minX2);
    int right = min(maxX1, maxX2);
    if (right > left) interX = right - left;
 
    int bottom = max(minY1, minY2);
    int top = min(maxY1, maxY2);
    if (top > bottom) interY = top - bottom;
 
    long long inter = interX * interY;
 
    cout << area1 + area2 - inter << '\n';
 
    return 0;
}
