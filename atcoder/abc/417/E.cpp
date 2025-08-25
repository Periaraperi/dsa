#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& vis, vector<int>& path, int e, bool& reached)
{
    path.emplace_back(v);
    vis[v] = true;
    if (v == e) {
        reached = true;
        return;
    }
    for (const auto& u:g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis, path, e, reached);
            if (reached) break;
            else {
                path.pop_back();
            }
        }
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        --x; --y;
        vector<vector<int>> graph(n);
        for (int i{}; i<m; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        for (int i{}; i<n; ++i) {
            sort(graph[i].begin(), graph[i].end());
        }

        vector<int> path; path.reserve(n);
        vector<bool> vis(n, false);
        bool reached {false};
        dfs(x, graph, vis, path, y, reached);
        for (int i{}; i<(int)path.size(); ++i) {
            cout << path[i]+1 << " ";
        }
        cout << '\n';
    }
    return 0;
}

