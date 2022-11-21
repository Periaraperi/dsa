#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin >> n >> q;
    vector<vector<char>> grid(n,vector<char>(n));
    for(auto& r:grid)
        for(auto& c:r) 
            cin >> c;
    
    vector<vector<int>> pref_sum2d(n+1,vector<int>(n+1,0));

    for(int row=1; row<=n; ++row) {
        for(int col=1; col<=n; ++col) {
            char ch = grid[row-1][col-1];
            int val = 0;
            if(ch=='*') val = 1;
            pref_sum2d[row][col] = pref_sum2d[row][col-1] + val;
        }
    }
    for(int col=1; col<=n; ++col) {
        for(int row=1; row<=n; ++row) {
            pref_sum2d[row][col] += pref_sum2d[row-1][col];
        }
    }

    while(q--) {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << pref_sum2d[r2][c2] - pref_sum2d[r2][c1-1] - pref_sum2d[r1-1][c2] + pref_sum2d[r1-1][c1-1] << '\n';
    }

    return 0;
}


