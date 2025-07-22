#include <iostream>
#include <queue>
#include <vector>
#include <array>
 
using namespace std;

array dis_r {-1, -1, -2, -2,  1, 1,  2, 2};
array dis_c {-2,  2, -1,  1, -2, 2, -1, 1};

struct Info {
    int i;
    int j;
    int c;
};

bool can_move(int r, int c, const vector<vector<bool>>& vis)
{
    return r < (int)vis.size() && r >= 0 && c < (int)vis.size() && c >= 0 && !vis[r][c];
}

void bfs(vector<vector<int>>& grid)
{
    vector vis(grid.size(), vector<bool>(grid.size(), false));
    queue<Info> q;
    q.push({0, 0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        const auto [r, c, m] {q.front()}; 
        q.pop();
        grid[r][c] = m;
        for (int i{}; i<(int)dis_r.size(); ++i) {
            const auto rr {r+dis_r[i]};
            const auto cc {c+dis_c[i]};
            if (can_move(rr, cc, vis)) {
                q.push({rr, cc, m+1});
                vis[rr][cc] = true;
            }
        }
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector grid(n, vector<int>(n, 0));
    bfs(grid);
    for (const auto& row:grid) {
        for (const auto& c:row) {
            cout << c << " ";
        }
        cout << '\n';
    }
    return 0;
}
