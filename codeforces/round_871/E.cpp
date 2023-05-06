#include <bits/stdc++.h>
 
using namespace std;

bool check(int i, int j, const vector<vector<int>>& g,
                               vector<vector<bool>>& vis)
{
    return (i>=0 && j>=0 && i<(int)g.size() && j<(int)g[0].size() && g[i][j]!=0 && !vis[i][j]);
}

int dir_row[4] = {1,-1,0, 0};
int dir_col[4] = {0, 0,1,-1};
int64_t dfs(int i, int j, const vector<vector<int>>& g,
                                vector<vector<bool>>& vis)
{
    int64_t cum = g[i][j];
    vis[i][j] = true;
    for (int k=0; k<4; ++k) {
        if (check(i+dir_row[k],j+dir_col[k],g,vis)) {
            cum += dfs(i+dir_row[k],j+dir_col[k],g,vis);
        }
    }
    return cum;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> g(n,vector<int>(m));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> g[i][j];
            }
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int64_t ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!vis[i][j] && g[i][j]!=0) {
                    ans = max(ans,dfs(i,j,g,vis));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

