#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<string> g(n);
        for (int i=0; i<n; ++i) {
            cin >> g[i];
        }
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (g[i][j]=='s') {
                    for (auto d:dir) {
                        int ii=i;
                        int jj=j;
                        string x;
                        while (ii<n && ii>=0 && jj<m && jj>=0) {
                            x += g[ii][jj];
                            if (x.size()==5) break;
                            ii += d.first;
                            jj += d.second;
                        }
                        if (x=="snuke") {
                            int ii=i;
                            int jj=j;
                            cout << ii+1 << " " << jj+1 << '\n';
                            for (int k=0; k<4; ++k) {
                                cout << ii+d.first+1 << " " << jj+d.second+1 << '\n';
                                ii += d.first;
                                jj += d.second;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

