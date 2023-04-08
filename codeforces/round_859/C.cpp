#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ok = true;
        for (int i='a'; i<='z'; ++i) {
            bool exists = false;
            for (const auto ch:s) {
                if (ch==i) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                int parity = -1;
                for (int j=0; j<n; ++j) {
                    if (s[j]==i) {
                        if (parity==-1) {
                            parity = j%2;
                        } else {
                            if (parity!=j%2) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }
            if (!ok) break;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

