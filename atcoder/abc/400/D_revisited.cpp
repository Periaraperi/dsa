#include <iostream>
#include <deque>
#include <vector>
#include <array>
 
using namespace std;

// my initial solution with priority queue and direction states is overkill
// simple 0-1 bfs works
 
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
    struct node {
        int v;
        short cost;
    };
    vector<vector<node>> graph(w*h);

    auto in_bounds = [h, w](int r, int c) {
        return r >= 0 && c >= 0 && r < h && c < w;
    };

    auto node_index = [w](int r, int c) {
        return r*w + c;
    };

    for (int i{}; i<h; ++i) {
        for (int j{}; j<w; ++j) {
            for (int k{}; k<4; ++k) {
                int r {i+dr[k]};
                int c {j+dc[k]};
                if (in_bounds(r, c)) {
                    if (grid[r][c] == '.') {
                        graph[node_index(i, j)].push_back({node_index(r, c), 0});
                    }
                    else if (grid[r][c] == '#') {
                        graph[node_index(i, j)].push_back({node_index(r, c), 1});
                    }

                    r += dr[k];
                    c += dc[k];
                    if (in_bounds(r, c) && grid[r][c] == '#') {
                        graph[node_index(i, j)].push_back({node_index(r, c), 1});
                    }
                }
            }
        }
    }

    vector<int> dis(w*h, INF);
    dis[node_index(A, B)] = 0;

    deque<int> q;
    q.push_front(node_index(A, B));

    while (!q.empty()) {
        const auto v {q.front()}; q.pop_front();
        for (const auto& [u, cost]:graph[v]) {
            if (dis[v]+cost < dis[u]) {
                dis[u] = dis[v]+cost;
                if (cost == 1) q.push_back(u);
                else q.push_front(u);
            }
        }
    }
    cout << dis[node_index(C, D)] << '\n';
    return 0;
}

