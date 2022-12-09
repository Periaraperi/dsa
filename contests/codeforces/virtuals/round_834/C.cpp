#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        long long l,r,x; cin >> l >> r >> x;
        long long a,b; cin >> a >> b;

        map<int,bool> mp;
        mp[a] = true;
        queue<pair<int,int>> q;
        q.push({a,0});
        long long ans = -1;
        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            auto aa = fr.first;
            if (aa==b) {
                ans = fr.second;
                break;
            }
            auto d = abs(aa-b);
            if (d>=x) {
                ans = fr.second+1;
                break;
            }

            if (aa+(x+d)<=r && !mp[aa+(x+d)])
                q.push({aa+(x+d),fr.second+1});
            if (aa+x<=r && !mp[aa+x])
                q.push({aa+x,fr.second+1});
            if (aa-(x+d)>=l && !mp[aa-(x+d)])
                q.push({aa-(x+d),fr.second+1});
            if (aa-x>=l && !mp[aa-x])
                q.push({aa-x,fr.second+1});
        }
        cout << ans << '\n';

    return 0;
}