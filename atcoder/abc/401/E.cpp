#include <iostream>
#include <vector>
 
using namespace std;

namespace peria {

struct dsu {
    explicit dsu(int n)
        :parent(n+1), sz(n+1)
    { for (int i{1}; i<=n; ++i) make_set(i); }
    
    void make_set(int a)
    { parent[a] = a; sz[a] = 1; }
 
    [[nodiscard]]
    int find_set(int a) // get representative of a's component 
    {
        if (a==parent[a]) return a;
        return (parent[a] = find_set(parent[a]));
    }
 
    void union_set(int a, int b) // join a's and b's components
    {
        auto st_a {find_set(a)};
        auto st_b {find_set(b)};
        if (st_a!=st_b) {
            if (sz[st_a]<sz[st_b])
                swap(st_a, st_b);
            parent[st_b] = st_a;
            sz[st_a] += sz[st_b];
        }
    }

    [[nodiscard]]
    int set_size(int a)
    { return sz[find_set(a)]; }
 
private:
    vector<int> parent;
    vector<int> sz;
};

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    // will track nodes with labels <= k in same sets. Should tell us
    // if 1..k could be 1 connected component.
    peria::dsu dsu(n+1);

    int bad_count {};
    vector<int> bad(n+1, false); // instead of set we can use boolean array and counter to count bad nodes. Removing extra log
    vector<int> ans(n+1, -1);

    for (int k{1}; k<=n; ++k) {
        if (bad[k]) { // maybe k was bad
            bad[k] = false;  
            --bad_count;
        }
        for (const auto& v:graph[k]) {
            if (v>k && !bad[v]) {
                bad[v] = true;
                ++bad_count;
            }
            if (v<k) dsu.union_set(k, v);
        }
        if (dsu.set_size(k) == k) ans[k] = bad_count;
    }

    for (int k{1}; k<=n; ++k) {
        cout << ans[k] << '\n';
    }

    return 0;
}

