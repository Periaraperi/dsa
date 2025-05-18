#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<char>> a(n,vector<char>(m));
        vector<vector<char>> b(n,vector<char>(m));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> b[i][j];
            }
        }

        auto check = [](const vector<vector<char>>& g1, const vector<vector<char>>& g2) -> bool {
             for (int i=0; i<g1.size(); ++i) {
                for (int j=0; j<g1[i].size(); ++j) {
                    if (g1[i][j]!=g2[i][j]) {
                        return false;
                    }
                }
             }
             return true;
        };

        auto get_grid = [](int i, int j, const vector<vector<char>>& a) {
            auto grid = a;
            for (int cnt=0; cnt<i; ++cnt) {
                for (int i=0; i<(int)grid.size()-1; ++i) {
                    swap(grid[i],grid[i+1]);
                }
            }
            for (int cnt=0; cnt<j; ++cnt) {
                for (int k=0; k<grid.size(); ++k) {
                    for (int col=0; col<grid[k].size()-1; ++col) {
                        swap(grid[k][col],grid[k][col+1]);
                    }
                }
            }
            return grid;
        };

        bool ok = false;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                auto new_grid = get_grid(i,j,a);
                if (check(new_grid,b)) {
                    ok = true;
                    break;
                }
            }
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

