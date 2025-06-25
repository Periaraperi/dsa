#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;

struct Node {
    int to{};
    int64_t w{};
};

void dfs(int v, const vector<vector<Node>>& graph, vector<Node>& tree, vector<bool>& vis, vector<int>& in_deg)
{
    if (vis[v]) return;
    vis[v] = true;
    
    for (auto u:graph[v]) {
        if (vis[u.to]) continue;
        tree[u.to] = {v, u.w};
        ++in_deg[v];
        dfs(u.to, graph, tree, vis, in_deg);
    }
}

vector<Node> root_tree(const vector<vector<Node>>& graph, vector<int>& in_deg)
{
    vector<Node> tree(graph.size());
    vector<bool> vis(graph.size(), false);

    // root at 0, just a random choice
    dfs(0, graph, tree, vis, in_deg);
    return tree;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int64_t> xs(n);
    for (auto& x:xs) cin >> x;
    vector<vector<Node>> graph(n);
    for (int i{}; i<n-1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        graph[u].emplace_back(Node{v, w});
        graph[v].emplace_back(Node{u, w});
    }

    vector<int> in_deg(n, 0);
    auto tree {root_tree(graph, in_deg)};
    
    queue<int> q;
    for (int i{}; i<n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    int64_t ans {};
    while (!q.empty()) {
        auto v {q.front()}; q.pop();
        auto [p, w] {tree[v]};
        if (xs[v] != 0) {
            ans += w*abs(xs[v]);
            xs[p] += xs[v];
        }
        --in_deg[p];
        if (in_deg[p] == 0) {
            q.push(p);
        }
    }

    cout << ans << '\n';
    return 0;
}

