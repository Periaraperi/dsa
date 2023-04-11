#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> grid(2,vector<int>(n));
        int x = 2*n;
        for (int i=0; i<n; i+=2) {
            grid[0][i] = x;
            grid[1][i+1] = x-1;
            x -= 2;
        }
        x = 1;
        for (int i=0; i<n; i+=2) {
            grid[1][i] = x;
            grid[0][i+1] = x+1;
            x += 2;
        }
        for (auto& i:grid) {
            for (auto& j:i) {
                if (j==2*n-1) 
                    swap(j,grid[1][n-1]);
            }
        }
        for (auto i:grid) {
            for (auto j:i) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}

