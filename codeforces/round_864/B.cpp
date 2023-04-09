#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,K; cin >> n >> K;
        vector<vector<int>> grid(n,vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> grid[i][j];
            }
        }
        
        int cnt = 0;
        for (int i=0; i<=n/2; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]!=grid[n-i-1][n-j-1]) {
                    grid[i][j] ^= 1;
                    ++cnt;
                }
            }
        }
        if (cnt>K) {
            cout << "NO\n";
        } else {
            if ((K-cnt)%2==0)
                cout << "YES\n";
            else {
                if (n%2==0) 
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
        }
    }
    return 0;
}
