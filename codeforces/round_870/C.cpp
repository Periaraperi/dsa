#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        if (m>=n) {
            if (n==1) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (m==1) cout << "YES\n";
            else {
                bool ok = false;
                for (int i=2; i*i<=n; ++i) {
                    if (n%i==0 && i<=m) {
                        ok = true; break;
                    }
                }
                if (ok) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}

