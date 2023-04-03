#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    constexpr int N = 50001;
    int t = 1; cin >> t;
    while(t--) {
        int m; cin >> m;
        vector<vector<int>> v(m);
        for (int i=0; i<m; ++i) {
            int n; cin >> n;
            v[i].resize(n);
            for (auto& x:v[i]) cin >> x;
        }

        vector<vector<int>> graph(m);
        vector<bool> vis(N,false);
        for (int i=m-1; i>=0; --i) {
            for (const auto p:v[i]) {
                if (!vis[p]) { 
                    graph[i].push_back(p);
                    vis[p] = true;
                }
            }
        }
        vector<int> ans;
        bool ok = true;
        for (int i=0; i<m; ++i) {
            if (graph[i].empty()) {
                ok = false;
                break;
            }
            ans.push_back(graph[i][0]);
        }
        if (ok) {
            for (const auto i:ans) 
                cout << i << " ";
        } else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}

