#include <bits/stdc++.h>
    
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 1; cin >> tt;
    while (tt--) {
        int n,k; cin >> n >> k;
        string s,t; cin >> s >> t;
        vector<int> freq_s(26), freq_t(26);
        for (auto ch:s) {
            ++freq_s[ch-'a'];
        }
        for (auto ch:t) {
            ++freq_t[ch-'a'];
        }
        bool ok = true;
        for (int i=0; i<26; ++i) {
            if (freq_s[i]!=freq_t[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            if (k>=n) {
                if (s==t) cout << "YES\n";
                else cout << "NO\n";
            } else if (k<=n/2) {
                cout << "YES\n";
            } else {
                bool ok = true;
                for (int i=0; i<n; ++i) {
                    if (i+k>=n && i-k<0) {
                        if (s[i]!=t[i]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    
    return 0;
}