#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i=0; i<m; ++i) {
           int u,v; cin >> u >> v;
           --u; --v;
           g[u].push_back(v);
           g[v].push_back(u);
           ++deg[v];
           ++deg[u];
        }

        vector<int> leaves;
        for (int i=0; i<n; ++i) {
            int d = deg[i];
            if (d==0 || d==1) {
                leaves.push_back(i);
                deg[i] = 0;
            }
        }

        int cnt = leaves.size();
        while (cnt<n) {
            vector<int> new_leaves;
            for (auto leaf:leaves) {
                for (auto u:g[leaf]) {
                    --deg[u];
                    if (deg[u]==1)
                        new_leaves.push_back(u);
                }
                deg[leaf] = 0;
            }
            cnt += new_leaves.size();
            leaves = new_leaves;
        }
        int center = leaves[0];

        cout << g[center].size() << " " << g[g[center][0]].size()-1 << '\n';

    }
    return 0;
}
