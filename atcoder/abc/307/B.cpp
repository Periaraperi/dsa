#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        bool ok = false;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==j) continue;
                string conc = v[i]+v[j];
                string tmp = conc;
                reverse(tmp.begin(),tmp.end());
                if (conc==tmp) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

