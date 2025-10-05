#include <iostream>
#include <queue>
#include <vector>
#include <string>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> grid(n);
    for (int i{}; i<n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dis(n, vector<int>(n, -1));

    struct info {
        int u {};
        int v {};
    };

    queue<info> q;
    for (int i{}; i<n; ++i) {
        q.push({i, i});
    }
    for (int i{}; i<n; ++i) {
        for (int j{}; j<n; ++j) {
            if (i == j) continue;
            if (grid[i][j] != '-') {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        const auto [u, v] {q.front()};
        q.pop();
        if (u==v) dis[u][v] = 0;
        else if (grid[u][v] != '-') {
            dis[u][v] = 1;
        }
        for (int back{}; back<n; ++back) {
            for (int forward{}; forward<n; ++forward) {
                if (grid[back][u] == grid[v][forward] && grid[back][u] != '-') {
                    const auto new_dis {dis[u][v]+2};
                    if (dis[back][forward] == -1) {
                        dis[back][forward] = new_dis;
                        q.push({back, forward});
                    }
                }
            }
        }
    }

    for (int i{}; i<n; ++i) {
        for (int j{}; j<n; ++j) {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

