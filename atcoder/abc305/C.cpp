#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<string> grid(n);
        for (int i=0; i<n; ++i)
            cin >> grid[i];
        bool ok = false;
        int ii,jj;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j]=='.') {
                    int cnt = 0;
                    if (i-1>=0 && grid[i-1][j]=='#') ++cnt;
                    if (i+1<n && grid[i+1][j]=='#') ++cnt;
                    if (j-1>=0 && grid[i][j-1]=='#') ++cnt;
                    if (j+1<m && grid[i][j+1]=='#') ++cnt;
                    if (cnt>=2) {
                        ii = i+1;
                        jj = j+1;
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) break;
        }
        cout << ii << " " << jj << '\n';
    }
    return 0;
}

