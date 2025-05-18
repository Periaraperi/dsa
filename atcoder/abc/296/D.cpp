#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        long long n,m; cin >> n >> m;
        constexpr long long nmax = 1e12;
        constexpr long long INF = 1e18;
        if (n>=m) cout << m << '\n';
        else {
            long long ans = INF;
            for (long long i=1; i*i<=nmax; ++i) {
                long long x = ceil((double)m/i);
                if (x<=n && i<=n) {
                    ans = min(ans,x*i);
                }
            }
            if (ans==INF) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
    return 0;
}

