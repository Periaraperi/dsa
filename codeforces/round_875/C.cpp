#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> tree(n);
        map<pair<int,int>,int> mp;
        for (int i=0; i<n-1; ++i) {
            int u,v; cin >> u >> v;
            --u; --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            mp[make_pair(u,v)] = i;
            mp[make_pair(v,u)] = i;
        }


        auto comp = [](const auto& x, const auto& y) -> bool {
            return x.second.first>y.second.first;
        };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(comp)> q(comp);
        vector<bool> vis(n);
        for (auto v:tree[0]) {
            q.push({v,{1,mp[make_pair(0,v)]}});
        }
        vis[0] = 1;

        int ans = 0;
        while (!q.empty()) {
            auto v = q.top();
            ans = max(ans,v.second.first);
            q.pop();
            vis[v.first] = true;
            
            for (auto u:tree[v.first]) {
                if (vis[u]) continue;
                if (mp[make_pair(v.first,u)]>v.second.second) {
                    q.push({u,{v.second.first,mp[make_pair(v.first,u)]}});
                } else {
                    q.push({u,{v.second.first+1,mp[make_pair(v.first,u)]}});
                }
            }
        }
        cout << ans << '\n';

    }
    return 0;
}

