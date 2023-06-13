#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; // cin >> t;
    while (t--) {
        int n,m,k; cin >> n >> m >> k;
        vector<vector<int>> graph(n);
        for (int i=0; i<m; ++i) {
            int a,b; cin >> a >> b;
            --a; --b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        priority_queue<pair<int,int>> q;
        vector<int> dd(n,-1);
        vector<int> p(k),h(k);

        for (int i=0; i<k; ++i) {
            cin >> p[i] >> h[i];
            --p[i];
            q.push({h[i],p[i]});
            dd[p[i]] = h[i];
        }

        while (!q.empty()) {
            auto [health,v] = q.top();
            q.pop();
            if (health==0) continue;
            for (auto u:graph[v]) {
                if (dd[u]<dd[v]-1) {
                    dd[u] = dd[v]-1;
                    q.push({dd[u],u});
                }
            }
        }

        vector<int> ans;
        for (int i=0; i<n; ++i) 
            if (dd[i]!=-1) ans.push_back(i);

        sort(ans.begin(),ans.end());
        cout << ans.size() << '\n';
        for (auto i:ans) cout << i+1 << " ";
        cout << '\n';
    }
    return 0;
}

