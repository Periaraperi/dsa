#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        int xr = 0;
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            xr ^= a;
        }
        if (n%2==0) {
            if (xr==0) cout << 0 << '\n';
            else cout << -1 << '\n';
        } else {
            cout << xr << '\n'; 
        }
    }
    return 0;
}

