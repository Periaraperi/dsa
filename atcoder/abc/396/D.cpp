#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;

struct node {
    int v{};
    int64_t w{};
};

void dfs(int v, const vector<vector<node>>& graph, vector<bool>& vis, int64_t& ans, int64_t& running_cost, const int& last)
{
    if (vis[v]) return;
    vis[v] = true;
    if (v == last) {
        ans = min(ans, running_cost);
        return;
    }

    for (const auto& [u, w]:graph[v]) {
        if (!vis[u]) {
            running_cost ^= w;
            dfs(u, graph, vis, ans, running_cost, last);
            vis[u] = false;
            running_cost ^= w;
        }
    }
    vis[v] = false;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<node>> graph(n);
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        int64_t w; cin >> w;
        --a; --b;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    int64_t ans{numeric_limits<int64_t>::max()};
    vector<bool> vis(n, false);
    int64_t running_cost{};
    dfs(0, graph, vis, ans, running_cost, n-1);
    cout << ans << '\n';

    return 0;
}

