#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
         int n; cin >> n;
         map<string,int> mp;
         constexpr int inf = 1e9;
         mp["11"] = inf;
         mp["10"] = inf;
         mp["01"] = inf;
         for (int i=0; i<n; ++i) {
            int m; cin >> m;
            string s; cin >> s;
            if (s=="00") continue;
            mp[s] = min(mp[s],m);
         }
         if (mp["11"]!=inf) {
            if (mp["10"]==inf || mp["01"]==inf) {
                cout << mp["11"] << '\n';
            } else {
                int64_t x = mp["10"]+mp["01"];
                if (x<mp["11"]) {
                    cout << x << '\n';
                } else {
                    cout << mp["11"] << '\n';
                }
            }
         } else {
            if (mp["10"]==inf || mp["01"]==inf) {
                cout << "-1\n";
            } else {
                cout << mp["10"]+mp["01"] << '\n';
            }
         }
    }
    return 0;
}

