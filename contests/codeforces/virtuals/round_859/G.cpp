#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(),v.end());
        bool ok = true;
        long long pref = v[0];
        if (v[0]!=1) {
            cout << "NO\n";
            continue;
        }
        for (int i=1; i<n; ++i) {
            if (v[i]>pref) {
                ok = false;
                break;
            }
            pref += v[i];
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

