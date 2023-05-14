#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n+1), f(n+1);
        
        int mn = n-1;
        for (int i=1; i<=n; ++i) {
            cin >> v[i];
            f[i] = abs(v[i]-i);
            if (f[i]==0) continue;
            mn = min(mn,f[i]);
        }
        
        int g = mn;
        for (int i=1; i<=n; ++i) {
            if (f[i]!=0) {
                g = __gcd(g,f[i]);
            }
        }
        cout << g << '\n';

    }
    return 0;
}

