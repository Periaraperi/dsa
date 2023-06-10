#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        vector<int> v(26);
        v['A'-'A'] = 0;
        v['B'-'A'] = 3;
        v['C'-'A'] = 1;
        v['D'-'A'] = 4;
        v['E'-'A'] = 1;
        v['F'-'A'] = 5;
        v['G'-'A'] = 9;
        char p,q; cin >> p >> q;
        if (p>q) swap(p,q);
        int ans = 0;
        for (char i=p+1; i<=q; ++i)
            ans += v[i-'A'];
        cout << ans << '\n';
    }
    return 0;
}

