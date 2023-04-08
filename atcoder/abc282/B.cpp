#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<string> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                bool ok = true;
                for (int k=0; k<m; ++k) {
                    if (v[i][k]=='x' && v[j][k]=='x') {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++ans;
            }
        }
        cout << ans;
    }
    return 0;
}