#include <iostream>
#include <vector>
 
using namespace std;

void dfs(int v, int d, const vector<vector<int>>& tree, vector<int>& depth)
{
    depth[v] = d;
    for (const auto& u:tree[v]) {
        dfs(u, d+1, tree, depth);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<vector<int>> tree(n);
    vector<int> parent(n);
    for (int i{1}; i<=n-1; ++i) {
        int a; cin >> a; --a;
        parent[i] = a;
        tree[a].emplace_back(i);
    }
    vector<int> depth(n, 0);
    dfs(0, 0, tree, depth);

    vector<vector<int>> jump(n, vector<int>(31, 0));
    for (int i{}; i<n; ++i) {
        jump[i][0] = parent[i];
    }
    for (int i{1}; i<=30; ++i) {
        for (int j{}; j<n; ++j) {
            jump[j][i] = jump[jump[j][i-1]][i-1];
        }
    }

    auto lca = [&depth, &jump](int a, int b) -> int {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        auto len {depth[a]-depth[b]};
        
        for (int i{30}; i>=0; --i) {
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

    while (q--) {
        int a, b; cin >> a >> b;
        --a; --b;
        cout << lca(a, b)+1 << '\n';
    }

    return 0;
}

