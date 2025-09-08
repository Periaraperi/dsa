#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector grid(N, vector<int64_t>(M));
    for (auto& row:grid) {
        for (auto& col:row) {
            cin >> col;
        }
    }
    vector<int64_t> v(N+M-1);
    for (auto& i:v) cin >> i;

    constexpr int64_t INF {numeric_limits<int64_t>::max()};
    vector min_amount(N, vector<int64_t>(M, INF)); // min amount of coins that I need to get from cell (i,j) to end.
    min_amount[N-1][M-1] = max((int64_t)0, v.back()-grid[N-1][M-1]);
    for (int i{N-1}; i>=0; --i) {
        for (int j{M-1}; j>=0; --j) {
            int prev_day {i+j-1};
            if (i-1 >= 0) min_amount[i-1][j] = max((int64_t)0, min(min_amount[i-1][j], v[prev_day]-grid[i-1][j]+min_amount[i][j]));
            if (j-1 >= 0) min_amount[i][j-1] = max((int64_t)0, min(min_amount[i][j-1], v[prev_day]-grid[i][j-1]+min_amount[i][j]));
        }
    }

    cout << min_amount[0][0] << '\n';
    return 0;
}
