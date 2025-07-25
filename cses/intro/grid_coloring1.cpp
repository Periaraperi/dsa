#include <iostream>
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

    array chars {'A', 'B', 'C', 'D'};

    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            const auto ch {grid[i][j]};
            for (const auto c:chars) {
                if (ch == c) continue;
                bool up {false};
                if (i-1 < 0) up = true;
                else if (grid[i-1][j] != c) up = true;
                bool left {false};
                if (j-1 < 0) left = true;
                else if (j-1 >= 0 && grid[i][j-1] != c) left = true;
                if (up && left) {
                    grid[i][j] = c;
                    break;
                }
            }
        }
    }

    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}

