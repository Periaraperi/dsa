#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto& i:grid)
        for (auto& j:i) 
            cin >> j;

    set<vector<char>> st;
    
    for (int i{}; i<n; ++i) {
        for (int j{}; j<n; ++j) {
            vector<char> u;
            for (int k{}; k<m; ++k) {
                if (i+k >= n) break;
                for (int l{}; l<m; ++l) {
                    if (j+l >= n) break;
                    u.emplace_back(grid[i+k][j+l]);
                }
            }
            if (static_cast<int>(u.size()) == m*m) {
                st.insert(std::move(u));
            }
        }
    }
    cout << st.size() << '\n';
    return 0;
}

