#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while (t--) {
        int n,d; cin >> n >> d;
        vector<pair<int,int>> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        vector<string> ans(n,"No");
        ans[0] = "Yes";
        queue<int> q;
        q.push(0);
        vector<bool> vis(n);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            vis[i] = 1;
            for (int j=0; j<n; ++j) {
                if (i==j || vis[j]) continue;
                auto [x,y] = v[i];
                auto [xx,yy] = v[j];
                if (d*d>=(x-xx)*(x-xx)+(y-yy)*(y-yy)) {
                    ans[j] = "Yes";
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
        for (int i=0; i<n; ++i) cout << ans[i] << '\n';
    }
    return 0;
}

