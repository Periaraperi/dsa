#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool isq = false;
        for (auto& ch:s) {
            if (ch=='?') {
                isq = true;
                break;
            }
        }
        if (!isq) cout << s << '\n';
        else {
            int n = (int)s.size();
            for (int i=0; i<n; ++i) {
                if (s[i]=='?') {
                    int j = i;
                    while (i+1<n && s[i+1]=='?') {
                        ++i;
                    }
                    if (i+1<n) {
                        if (j-1>=0 && s[i+1]==s[j-1]) {
                            for (int k=j; k<i+1; ++k) s[k] = s[i+1];
                        } else {
                            for (int k=j; k<i+1; ++k) s[k] = '0';
                        }
                    } else {
                        if (j-1>=0) {
                            for (int k=j; k<n; ++k) s[k] = s[j-1];
                        } else {
                            for (int k=j; k<n; ++k) s[k] = '0';
                        }
                    }
                }
            }
            cout << s << '\n';
        }
    }
    return 0;
}

