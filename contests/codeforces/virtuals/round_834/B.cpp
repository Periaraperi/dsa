#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        int m,s; cin >> m >> s;
        vector<bool> used(51,false);
        vector<int> v(m);
        int mx = 0;
        for (int i=0; i<m; ++i) {
            cin >> v[i];
            used[v[i]] = true;
            mx = max(mx,v[i]);
        }
        
        int sm = 0;
        for (int i=1; i<=mx; ++i) {
            if (!used[i]) {
                sm += i;
            }
        }
        s -= sm;
        if (s<0) {
            cout << "NO\n";
            continue;
        }
        if (sm>0 && s==0) {
            cout << "YES\n";
            continue;
        }

        int k = mx+1;
        bool ok = true;
        while (1) {
            s -= k;
            if (s==0) {
                ok = true;
                break;
            } else if (s<0) {
                ok = false;
                break;
            }
            ++k;
        }
        cout << ((ok) ? "YES":"NO") << '\n';

    }

    return 0;
}