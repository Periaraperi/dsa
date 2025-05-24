#include <iostream>
#include <vector>
 
using namespace std;

void recurse(const vector<vector<int64_t>>& grid, int linear_index, vector<vector<bool>>& used, int64_t running_score, int64_t& score)
{
    int N {(int)grid.size()};
    int M {(int)grid[0].size()};

    if (linear_index == N*M) return;

    recurse(grid, linear_index+1, used, running_score, score);

    int r {linear_index / M};
    int c {linear_index % M};

    if (c+1 < M && !used[r][c] && !used[r][c+1] ) {
        used[r][c] = used[r][c+1] = true;
        running_score ^= (grid[r][c] ^ grid[r][c+1]);
        score = max(score, running_score);
        recurse(grid, linear_index+1, used, running_score, score);
        used[r][c] = used[r][c+1] = false;
        running_score ^= (grid[r][c] ^ grid[r][c+1]);
    }

    if (r+1 < N && !used[r][c] && !used[r+1][c] ) {
        used[r][c] = used[r+1][c] = true;
        running_score ^= (grid[r][c] ^ grid[r+1][c]);
        score = max(score, running_score);
        recurse(grid, linear_index+1, used, running_score, score);
        used[r][c] = used[r+1][c] = false;
        running_score ^= (grid[r][c] ^ grid[r+1][c]);
    }

    score = max(score, running_score);
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int64_t>> grid(n, vector<int64_t>(m));
    int64_t score {};
    for (int i{}; i<n; ++i) {
        for (int j{}; j<m; ++j) {
            cin >> grid[i][j];
            score ^= grid[i][j];
        }
    }
    vector<vector<bool>> used(n, vector<bool>(m, false));

    int64_t final_score {};
    recurse(grid, 0, used, score, final_score);
    cout << final_score << '\n';

    return 0;
}

