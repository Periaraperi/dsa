#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; long long d; cin >> n >> d;
        vector<long long> v(n);
        for (auto&& i:v) cin >> i;
        int ok = -1;
        for (int i=1; i<n; ++i) {
            if (v[i]-v[i-1]<=d) {
                ok = i; break;
            }
        }
        if (ok!=-1) cout << v[ok] << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}

