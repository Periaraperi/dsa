#include <iostream>
#include <vector>
 
using namespace std;

struct info {
    int depth {}; // depth of each node starting from root of tree
    int64_t depth_sum {}; // sum of depths for each node
    int64_t depth_sum2 {}; // sum of depths for each node where depth of node(i) is considered as 0
    int size {}; // size of subtree rooted at node(i)
    int64_t depth_sum_above {}; // cummulative sum of path lengths from node(i) to every other node which is not below node(i) (i.e. non-child nodes)
};

// root a tree and calculate information for each node excluding 'depth_sum_above'
void dfs(int v, const vector<vector<int>>& tree, vector<vector<int>>& rooted_tree, vector<bool>& vis, vector<info>& info)
{
    if (vis[v]) return;
    vis[v] = true;

    for (const auto& u:tree[v]) {
        if (vis[u]) continue;
        rooted_tree[v].emplace_back(u);
        info[u].depth = info[v].depth + 1;
        dfs(u, tree, rooted_tree, vis, info);
        info[v].size += info[u].size;
        info[v].depth_sum += (info[u].depth+info[u].depth_sum);
    }
    ++info[v].size;

    info[v].depth_sum2 = (info[v].depth_sum - (info[v].size-1)*info[v].depth);
}

// calculate 'depth_sum_above' for each node
void dfs(int v, vector<vector<int>>& rooted_tree, vector<info>& info)
{
    const int n {static_cast<int>(rooted_tree.size())};
    for (const auto& u:rooted_tree[v]) {
        // x = sum of depths of subtree rooted at v excluding child u
        auto x {info[v].depth_sum2 - ((info[u].depth-info[v].depth)*info[u].size + info[u].depth_sum2)};

        x += (info[v].size-info[u].size); // for each path from u to other children of v we need to add 1.

        info[u].depth_sum_above += (x + info[v].depth_sum_above + (n-info[v].size));

        dfs(u, rooted_tree, info);
    }
}

void root_tree(const vector<vector<int>>& tree, vector<vector<int>>& rooted_tree, vector<info>& info)
{
    vector<bool> vis(tree.size(), false);
    dfs(0, tree, rooted_tree, vis, info);
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> rooted_tree(n);
    vector<info> info(n);
    {
        vector<vector<int>> tree(n);
        for (int i{}; i<n-1; ++i) {
            int a, b; cin >> a >> b;
            --a; --b;
            tree[a].emplace_back(b);
            tree[b].emplace_back(a);
        }
        root_tree(tree, rooted_tree, info);
    }

    dfs(0, rooted_tree, info);

    for (int i{}; i<n; ++i) {
        cout << info[i].depth_sum2+info[i].depth_sum_above << " ";
    }
    cout << '\n';

    return 0;
}

