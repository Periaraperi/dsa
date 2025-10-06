#include <iostream>
#include <queue>
#include <vector>
#include <array>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector grid(n, vector<char>(m));
    for (auto& row:grid) {
        for (auto& c:row) {
            cin >> c;
        }
    }

    struct info {
        int r {};
        int c {};
        int level {};
    };
    queue<info> q;

    auto can_color = [&grid, n, m](int i, int j) {
        if (!(i>=0 && j>=0 && i<n && j<m) || grid[i][j] == '#') return false;
        int c {};
        if (i-1>=0 && grid[i-1][j] == '#') ++c;
        if (i+1<n  && grid[i+1][j] == '#') ++c;
        if (j-1>=0 && grid[i][j-1] == '#') ++c;
        if (j+1<m  && grid[i][j+1] == '#') ++c;
        return c==1;
    };

    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            if (grid[i][j]=='#') {
                q.push({i, j, 0});
            }
        }
    }

    array dr {1, -1, 0,  0};
    array dc {0,  0, 1, -1};

    int prev_level {};
    vector<info> to_color;

    vector vis(n, vector<bool>(m, false));
    
    while (!q.empty()) {
        const auto [i, j, level] {q.front()};
        q.pop();
        if (prev_level != level) {
            for (const auto& x:to_color) {
                grid[x.r][x.c] = '#';
            }
            to_color.clear();
        }
        prev_level = level;
        for (int k{}; k<4; ++k) {
            const auto r {dr[k]+i};
            const auto c {dc[k]+j};
            if (can_color(r, c) && !vis[r][c]) {
                to_color.push_back({r, c});
                q.push({r, c, level+1});
                vis[r][c] = true;
            }
        }
    }

    int ans {};
    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            if (grid[i][j]=='#') {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

