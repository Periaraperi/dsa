#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<bool> v(26,false);
        for (auto& ch:s) v[ch-'a'] = true;
        int ans = 0;
        for (int i=25; i>=0; --i) {
            if (v[i]) {
                ans = i+1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

