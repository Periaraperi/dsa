#include <iostream>
#include <vector>
 
using namespace std;

void root_dfs(int v, int d, int p, 
              const vector<vector<int>>& tree, 
              vector<bool>& vis, 
              vector<vector<int>>& rooted_tree, 
              vector<int>& depth,
              vector<int>& parent)
{
    if (vis[v]) return;
    vis[v] = true;
    parent[v] = p;

    for (const auto& u:tree[v]) {
        if (vis[u]) continue;
        rooted_tree[v].push_back(u);
        depth[u] = d+1;
        root_dfs(u, d+1, v, tree, vis, rooted_tree, depth, parent);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<vector<int>> rooted_tree(n);
    vector<int> depth(n, 0);
    vector<int> parent(n, 0);
    {
        vector<vector<int>> tree(n);
        for (int i{}; i<n-1; ++i) {
            int a, b; cin >> a >> b;
            --a; --b;
            tree[a].emplace_back(b);
            tree[b].emplace_back(a);
        }
        vector<bool> vis(n, false);
        root_dfs(0, 0, 0, tree, vis, rooted_tree, depth, parent);
    }

    vector<vector<int>> jump(n, vector<int>(31, 0));
    for (int i{1}; i<n; ++i) {
        jump[i][0] = parent[i];
    }
    for (int i{1}; i<=30; ++i) {
        for (int j{1}; j<n; ++j) {
            jump[j][i] = jump[jump[j][i-1]][i-1];
        }
    }

    auto lca = [&jump, &depth](int a, int b) -> int {
        if (depth[a] < depth[b]) swap(a, b);
        auto len {depth[a]-depth[b]};
        for (int i{30}; i>=0 && len>0; --i) {
            if ((1<<i) <= len) {
                a = jump[a][i];
                len -= (1<<i);
            }
        }
        if (a == b) return a;

        for (int i{30}; i>=0; --i) {
            if (jump[a][i] != jump[b][i]) {
                a = jump[a][i];
                b = jump[b][i];
            }
        }
        
        return jump[a][0];
    };

    while(q--) {
        int a, b; cin >> a >> b;
        --a; --b;
        cout << depth[a]+depth[b]-2*depth[lca(a, b)] << '\n';
    }
    return 0;
}

