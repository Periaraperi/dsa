#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        string s; cin >> s;
        int64_t n; cin >> n;
        int64_t m = s.size();

        vector<int> changed(m);
        int64_t x = 0;
        for (int i=0; i<m; ++i) {
            if (s[i]=='?') {
                s[i] = '0';
                changed[i] = true;
            }
            if (s[i]=='1') x += (1LL<<(m-i-1LL));
        }
        if (x>n) cout << "-1\n";
        else {
            for (int i=0; i<m; ++i) {
                if (changed[i]) {
                    if (x+(1LL<<(m-i-1LL))<=n) {
                        x += (1LL<<(m-i-1LL));
                    }
                }
            }
            cout << x << '\n';
        }
    }
    return 0;
}

