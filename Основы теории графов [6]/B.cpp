#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int N, M;
    cin >> N >> M;
  
    vector<string> grid(N);
  
    for (int i = 0; i < N; ++i) cin >> grid[i];
    int x, y;
    cin >> x >> y;
    --x; --y;
  
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
      
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
  
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << dist[i][j] << ' ';
        }
      
        cout << '\n';
    }
  
    return 0;
}
