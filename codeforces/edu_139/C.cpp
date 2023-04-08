#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<vector<char>>& grid, int row, int col, int black)
{
    int nCols = (int) grid[0].size();
    if (col==-1) return false;
    vector<vector<bool>> vis(2,vector<bool>(grid[0].size(),false));

    int i = row;
    int j = col;
    --black;
    while (black>0) {
        vis[i][j] = 1;
        if (i==0) {
            if (j<nCols && !vis[i+1][j] && grid[i+1][j]=='B') {
                ++i;
                --black;
            } else if (j+1<nCols && !vis[i][j+1] && grid[i][j+1]=='B') {
                ++j;
                --black;
            } else {
                return false;
            }
        } else {
            if (j<nCols && !vis[i-1][j] && grid[i-1][j]=='B') {
                --i;
                --black;
            } else if (j+1<nCols && !vis[i][j+1] && grid[i][j+1]=='B') {
                ++j;
                --black;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1; cin >> tt;
    while (tt--) {
        int nCols; cin >> nCols;
        int black = 0;
        vector<vector<char>> grid(2,vector<char>(nCols));
        for (int i=0; i<2; ++i) {
            for (int j=0; j<nCols; ++j) {
                cin >> grid[i][j];
                if (grid[i][j]=='B') 
                    ++black;
            }
        }
        int start_up = -1;
        int start_low = -1;
        for (int i=0; i<nCols; ++i) {
            if (grid[0][i]=='B') {
                start_up = i;
                break;
            }
        }
        for (int i=0; i<nCols; ++i) {
            if (grid[1][i]=='B') {
                start_low = i;
                break;
            }
        }
        
        if (black==0 || solve(grid,0,start_up,black) || solve(grid,1,start_low,black)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}