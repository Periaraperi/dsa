#include <iostream>
#include <vector>
 
using namespace std;

struct info {
    int in  {};
    int out {};
};

void root_dfs(int v, const vector<vector<int>>& tree, vector<bool>& vis, vector<vector<int>>& rooted_tree)
{
    if (vis[v]) return;
    vis[v] = true;
    for (const auto& u:tree[v]) {
        if (vis[u]) continue;
        rooted_tree[v].emplace_back(u);
        root_dfs(u, tree, vis, rooted_tree);
    }
}

void dfs(int v, int t, vector<vector<int>>& rooted_tree, vector<info>& info)
{
    info[v].in = t;
    info[v].out = t;
    if (rooted_tree[v].empty()) {
        info[v].out = info[v].in;
        return;
    }
    for (const auto& u:rooted_tree[v]) {
        dfs(u, info[v].out+1, rooted_tree, info);
        info[v].out = info[u].out;
    }
}

namespace peria {

template<std::integral T>
struct fenwick {
    explicit fenwick(int n)
        :v(vector<T>(n+1, 0))
    {}

    void update(int i, T increment)
    {
        while(i < static_cast<int>(v.size())) {
            v[i] += increment;
            i += (i&-i);
        }
    }

    [[nodiscard]]
    T query(int i) // sum from [0, i]
    {
        T sum {};
        while(i > 0) {
            sum += v[i];
            i -= (i&-i);
        }
        return sum;
    }

private:
    vector<T> v;
};

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;

    vector<int> values(n);
    vector<vector<int>> rooted_tree(n);
    vector<info> info(n);

    for (auto& i:values) cin >> i;
    {
        vector<vector<int>> tree(n);
        for (int i{}; i<n-1; ++i) {
            int a, b; cin >> a >> b;
            --a; --b;
            tree[a].emplace_back(b);
            tree[b].emplace_back(a);
        }
        vector<bool> vis(n, false);
        root_dfs(0, tree, vis, rooted_tree);
    }
    dfs(0, 1, rooted_tree, info);

    vector<int64_t> flattened(n+1, 0); // 1 based indexing
    for (int i{}; i<n; ++i) {
        flattened[info[i].in] = values[i];
    }

    peria::fenwick<int64_t> range_sum{n+1};
    for (int i{1}; i<=n; ++i) {
        range_sum.update(i, flattened[i]);
    }

    while (q--) {
        int op, s; cin >> op >> s;
        --s;
        const auto i {info[s].in};
        if (op == 1) {
            int64_t x; cin >> x;
            range_sum.update(i, x-flattened[i]);
            flattened[i] = x;
        }
        else {
            cout << range_sum.query(info[s].out)-range_sum.query(i-1) << '\n';
        }
    }

    return 0;
}

