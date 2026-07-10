#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, u, v;
    cin >> n >> m >> u >> v;
 
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
 
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[v] = 0;
    q.push(v);
 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : g[cur]) {
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                q.push(to);
            }
        }
    }
 
    if (dist[u] == -1) {
        cout << -1 << '\n';
        return 0;
    }
 
    vector<int> path;
    int cur = u;
    while (cur != v) {
        path.push_back(cur);
        for (int to : g[cur]) {
            if (dist[to] == dist[cur] - 1) {
                cur = to;
                break;
            }
        }
    }
    path.push_back(v);
 
    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
 
    return 0;
}
