#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i=0; i<n-1; ++i) {
            int a,b; cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
            ++deg[a];
            ++deg[b];
        }

        set<pair<int,int>> st; // {degree, vertex}
        for (int i=0; i<n; ++i) {
            st.insert({deg[i],i});
        }

        vector<int> ans;
        vector<bool> vis(n,false);
        while (!st.empty()) {
            auto [d,v] = *st.begin();
            st.erase(st.begin());
            if (!vis[v]) {
                vis[v] = true;
                if (d==1) { // leaf
                    int root = (vis[g[v][0]]) ? g[v][1]:g[v][0];
                    vis[root] = true;
                    ans.push_back((int)g[root].size());
                    for (auto u:g[root]) {
                        if (!vis[u]) {
                            vis[u] = true;
                            if (deg[u]==1) {
                                st.erase({1,u});
                            } else {
                                st.erase({deg[u],u});
                                int k = (g[u][0]==root) ? g[u][1] : g[u][0];
                                st.erase({deg[k],k});
                                st.insert({deg[k]-1,k});
                                --deg[k];
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        for (auto i:ans) cout << i << " ";

    }
    return 0;
}

