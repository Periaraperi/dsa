#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

struct Node {
    int i, j, d;
};

struct Cell {
    int i, j;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W, ' '));

    bool exit_exists {false};
    bool empty_cell_exists {false};
    for (int i{}; i<H; ++i) {
        for (int j{}; j<W; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                empty_cell_exists = true;
            }
            if (grid[i][j] == 'E') {
                exit_exists = true;
            }
        }
    }

    if (!exit_exists || !empty_cell_exists) {
        for (int i{}; i<H; ++i) {
            for (int j{}; j<W; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    else {

        constexpr int INF {10000000};
        vector<vector<int>> dis_grid(H, vector<int>(W, INF));
        for (int i{}; i<H; ++i) {
            for (int j{}; j<W; ++j) {
                if (grid[i][j] == 'E') {
                    dis_grid[i][j] = 0;
                }
            }
        }

        auto check = [&grid, H, W](int i, int j) {
            return i>=0 && j>=0 && i<H && j<W && grid[i][j] != '#';
        };

        auto get_arrow = [](int di, int dj) {
            // these are reversed
            if (dj == 1) {
                return '<';
            }
            if (dj == -1) {
                return '>';
            }

            if (di == 1) {
                return '^';
            }
            if (di == -1) {
                return 'v';
            }
            return ' ';
        };

        queue<Node> q;
        for (int i{}; i<H; ++i) {
            for (int j{}; j<W; ++j) {
                if (grid[i][j] == 'E') {
                    q.push(Node{i, j, 0});
                }
            }
        }

        vector<Cell> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            Node n {q.front()};
            q.pop();

            for (const auto& [di, dj]:dirs) {
                Cell new_cell {n.i + di, n.j + dj};
                if (check(new_cell.i, new_cell.j) && dis_grid[new_cell.i][new_cell.j] > n.d+1) {
                    dis_grid[new_cell.i][new_cell.j] = n.d+1;
                    grid[new_cell.i][new_cell.j] = get_arrow(di, dj);
                    q.push(Node{new_cell.i, new_cell.j, n.d + 1});
                }
            }
        }

        for (int i{}; i<H; ++i) {
            for (int j{}; j<W; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}

