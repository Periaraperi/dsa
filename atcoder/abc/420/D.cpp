#include <iostream>
#include <queue>
#include <vector>
#include <array>
 
using namespace std;

struct info {
    int i{};
    int j{};
    int dis{};
    bool switched{false};
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int si, sj, ei, ej;
    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'G') {
                ei = i;
                ej = j;
            }
        }
    }

    auto check = [&](int i, int j, bool switched) {
        if (i<0 || j<0 || i>=n || j >= m) return false;
        if (grid[i][j] == '#') return false;
        if (grid[i][j] == 'x' && !switched) return false;
        if (grid[i][j] == 'o' && switched) return false;
        return true;
    };

    queue<info> q;

    array<int, 4> di {0,  0, 1, -1};
    array<int, 4> dj {1, -1, 0,  0};

    constexpr int INF {100000000};
    vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(2, INF)));
    q.push({si, sj, 0, false});

    while (!q.empty()) {
        const auto curr {q.front()};
        q.pop();
        if (const auto d {dis[curr.i][curr.j][curr.switched]}; d < curr.dis) continue;
        for (int k{}; k<4; ++k) {
            int ii {curr.i + di[k]};
            int jj {curr.j + dj[k]};
            if (check(ii, jj, curr.switched)) {
                info info{ii, jj, curr.dis+1, curr.switched};
                if (grid[ii][jj] == '?') info.switched = !curr.switched;
                if (dis[ii][jj][info.switched] > info.dis) {
                    q.push(info);
                    dis[ii][jj][info.switched] = info.dis;
                }
            }
        }
    }

    auto ans {min(dis[ei][ej][0], dis[ei][ej][1])};
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}

