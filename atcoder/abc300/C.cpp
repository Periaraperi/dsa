#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<char>> grid(n,vector<char>(m));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> grid[i][j];
            }
        }

        auto is_center = [](int i, int j, const vector<vector<char>>& g) -> bool {
            int n = g.size();
            int m = g[0].size();
            return (g[i][j]=='#' && (i-1>=0 && j-1>=0 && g[i-1][j-1]=='#') &&
                                    (i-1>=0 && j+1<m  && g[i-1][j+1]=='#') &&
                                    (i+1<n  && j-1>=0 && g[i+1][j-1]=='#') &&
                                    (i+1<n  && j+1<m  && g[i+1][j+1]=='#'));
        };

        int x = min(n,m);
        vector<int> ans(x+1,0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (is_center(i,j,grid)) {
                    int k = 1;
                    int cnt = 0;
                    while (i-k>=0 && j-k>=0 && grid[i-k][j-k]=='#') {
                        ++cnt;
                        ++k;
                    }
                    ++ans[cnt];
                }
            }
        }
        for (int i=1; i<=x; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}

