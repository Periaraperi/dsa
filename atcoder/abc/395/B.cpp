#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector grid(n, vector<char>(n, '.'));

    int row_top {0};
    int row_bot {n-1};
    int col_left {0};
    int col_right {n-1};

    while (row_top<=row_bot && col_left<=col_right) {
        for (int i{col_left}; i<=col_right; ++i) {
            grid[row_top][i] = '#';
            grid[row_bot][i] = '#';
        }
        for (int i{row_top}; i<=row_bot; ++i) {
            grid[i][col_left] = '#';
            grid[i][col_right] = '#';
        }
        row_top += 2;
        row_bot -= 2;
        col_left += 2;
        col_right -= 2;
    }

    for (const auto& row:grid) {
        for (const auto& c:row) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}

