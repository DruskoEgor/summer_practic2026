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
 
    vector<int> parent(n + 1, -1);
    vector<int> it(n + 1, 0);
    stack<int> st;
 
    parent[u] = 0;
    st.push(u);
 
    while (!st.empty()) {
        int cur = st.top();
        if (cur == v) break;
 
        if (it[cur] < (int)g[cur].size()) {
            int to = g[cur][it[cur]];
            it[cur]++;
            if (parent[to] == -1) {
                parent[to] = cur;
                st.push(to);
            }
        } else {
            st.pop();
        }
    }
 
    if (parent[v] == -1) {
        cout << -1 << '\n';
        return 0;
    }
 
    vector<int> path;
    for (int cur = v; cur != 0; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
 
    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
 
    return 0;
}
