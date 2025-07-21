#include <iostream>
#include <array>
#include <vector>
 
using namespace std;

struct Cell {
    int r;
    int c;
};

bool can_place(const array<array<char, 8>, 8>& grid, int row, int col, const vector<Cell>& placed_queens)
{
    bool ok {row >= 0 && row < (int)grid.size() && col >= 0 && col < (int)grid.size() && grid[row][col] == '.'};
    if (!ok) return false;
    for (const auto& [r, c]:placed_queens) {
        if (abs(row-r) == abs(col-c) || abs(col-c) == 0 || abs(row-r) == 0) {
            ok = false;
            break;
        }
    }
    return ok;
}

int count_places(array<array<char, 8>, 8>& grid, int row, vector<Cell>& placed_queens)
{
    if (row == (int)grid.size()) {
        return 1;
    }
    int count {};
    for (int c{}; c<(int)grid.size(); ++c) {
        if (can_place(grid, row, c, placed_queens)) {
            placed_queens.push_back({row, c});
            count += count_places(grid, row+1, placed_queens);
            placed_queens.pop_back();
        }
    }
    return count;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<char, 8>, 8> grid;
    for (auto& row:grid) {
        for (auto& c:row) {
            cin >> c;
        }
    }

    vector<Cell> placed_queens; placed_queens.reserve(8);
    cout << count_places(grid, 0, placed_queens) << '\n';

    return 0;
}
