#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        map<string,int> mp;
        bool ok = false;
        for (int i=0; i<n-1; ++i) {
            string tmp = ""; tmp += s[i]; tmp += s[i+1];
            if (mp.find(tmp)!=mp.end()) {
                if (mp[tmp]<i) {
                    ok = true;
                    break;
                }
            } else {
                mp[tmp] = i+1;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }

    return 0;
}