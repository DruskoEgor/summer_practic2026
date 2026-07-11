#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, long long>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    const long long INF = 4e18;
    vector<long long> dist(n + 1, 0);
    dist[s] = INF;

    priority_queue<pair<long long, int>> pq;
    pq.push({INF, s});

    while (!pq.empty()) {
        auto [curW, v] = pq.top();
        pq.pop();
        if (curW != dist[v]) continue;

        for (auto [to, w] : g[v]) {
            long long newW = min(curW, w);
            if (newW > dist[to]) {
                dist[to] = newW;
                pq.push({newW, to});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        if (i == s) cout << -1;
        else cout << dist[i];
    }
    cout << '\n';

    return 0;
}
