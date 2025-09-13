#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    struct Cell {
        int i, j, h;
    };
public:
    int inf = numeric_limits<int>::max();
    bool findSafeWalk(vector<vector<int>>& grid, int health)
    {
        queue<Cell> q;
        if (grid[0][0] == 1)
            q.push({0, 0, health-1});
        else
            q.push({0, 0, health});
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), inf));

        auto check = [&](int i, int j) -> bool {
            return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
        };

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            if (cell.h <= 0) continue;
            
            if (cell.i == grid.size()-1 && cell.j == grid[0].size()-1)
                return true;

            if ((vis[cell.i][cell.j] == inf) || (vis[cell.i][cell.j] != inf && cell.h > vis[cell.i][cell.j])) {
                vis[cell.i][cell.j] = cell.h;
                if (check(cell.i+1, cell.j)) {
                    auto nh = cell.h - grid[cell.i+1][cell.j];
                    q.push({cell.i+1, cell.j, nh});
                }
                if (check(cell.i-1, cell.j)) {
                    auto nh = cell.h - grid[cell.i-1][cell.j];
                    q.push({cell.i-1, cell.j, nh});
                }
                if (check(cell.i, cell.j+1)) {
                    auto nh = cell.h - grid[cell.i][cell.j+1];
                    q.push({cell.i, cell.j+1, nh});
                }
                if (check(cell.i, cell.j-1)) {
                    auto nh = cell.h - grid[cell.i][cell.j-1];
                    q.push({cell.i, cell.j-1, nh});
                }
            }
        }
        return false;
    }
};

int main()
{
}
