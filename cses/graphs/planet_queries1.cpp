#include <bits/stdc++.h>
 
using namespace std;
 

// had other ideas, some interesting observations, but they were wrong overall
// needed binary lifting

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    
    vector<vector<int>> jump(31,vector<int>(n));
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        --a;
        jump[0][i] = a;
    }

    for (int i=1; i<=30; ++i)
        for (int j=0; j<n; ++j)
            jump[i][j] = jump[i-1][jump[i-1][j]];
    
    while (q--) {
        int x,k; cin >> x >> k;
        --x;
        for (int i=30; i>=0; --i) {
            if ((1<<i)<=k) {
                x = jump[i][x];
                k -= (1<<i);
            }
        }
        cout << x+1 << '\n';
    }

    return 0;
}

