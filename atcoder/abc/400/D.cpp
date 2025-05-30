#include <iostream>
#include <queue>
#include <vector>
#include <array>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w; cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i{}; i<h; ++i) {
        for (int j{}; j<w; ++j) {
            cin >> grid[i][j];
        }
    }
    int A, B, C, D; cin >> A >> B >> C >> D;
    --A; --B; --C; --D;

    array<int, 4> dr {0, 1,  0, -1};
    array<int, 4> dc {1, 0, -1, 0};

    constexpr int INF {100000000};
    vector<vector<vector<int>>> dis(h, vector<vector<int>>(w, vector<int>(4, INF))); // store minimum number of kicks required to get to cell (i,j) with direction in mind

    struct info {
        int r;
        int c;
        int kick_count;
        int dir;
    };
    auto comp = [](const info& a, const info& b) { // min priority queue
        return a.kick_count > b.kick_count;
    };

    priority_queue<info, vector<info>, decltype(comp)> q(comp);
    q.push({A, B, 0, 0});
    q.push({A, B, 0, 1});
    q.push({A, B, 0, 2});
    q.push({A, B, 0, 3});

    auto in_bounds = [h, w](int r, int c) {
        return r >= 0 && c >= 0 && r < h && c < w;
    };

    while (!q.empty()) {
        const auto [r, c, kicks, dir] {q.top()}; q.pop();
        for (int i{}; i<4; ++i) {
            int rr {r+dr[i]};
            int cc {c+dc[i]};
            if (in_bounds(rr, cc)) {
                if (grid[rr][cc] == '.') {
                    if (dis[rr][cc][i] > kicks) {
                        q.push({rr, cc, kicks, i});
                        dis[rr][cc][i] = kicks;
                    }
                }
                else {
                    if (dis[rr][cc][i] > kicks+1) {
                        q.push({rr, cc, kicks+1, i});
                        dis[rr][cc][i] = kicks+1;
                    }
                    if (in_bounds(rr+dr[i], cc+dc[i])) {
                        if (dis[rr+dr[i]][cc+dc[i]][i] > kicks+1) {
                            q.push({rr+dr[i], cc+dc[i], kicks+1, dir});
                            dis[rr+dr[i]][cc+dc[i]][i] = kicks+1;
                        }
                    }
                }
            }
        }
    }

    int ans {INF};
    for (int i{}; i<4; ++i) ans = min(ans, dis[C][D][i]);
    cout << ans << '\n';
    return 0;
}

