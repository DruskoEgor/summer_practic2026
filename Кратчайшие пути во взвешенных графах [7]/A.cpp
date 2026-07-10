#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 4e18;
 
struct Edge {
    int u, v;
    long long w;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, s;
    cin >> n >> m >> s;
 
    vector<Edge> edges;
    edges.reserve(m);
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
 
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;
 
    for (int it = 0; it < n - 1; ++it) {
        bool updated = false;
        for (const auto &e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }
 
    for (const auto &e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            cout << "Negative cycle\n";
            return 0;
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        if (dist[i] == INF) cout << "inf";
        else cout << dist[i];
    }
    cout << '\n';
 
    return 0;
}
