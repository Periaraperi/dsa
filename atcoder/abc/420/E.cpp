#include <iostream>
#include <vector>
 
using namespace std;

struct DSU { // 1 based
    DSU(int n)
        :parent(n+1), sz(n+1), count_blacks(n+1)
    {
        for (int i{1}; i<=n; ++i)
            make_set(i);
    }
    
    void make_set(int a)
    {
        parent[a] = a;
        sz[a] = 1;
    }
 
    int find_set(int a) // get representative of a's component 
    {
        if (a == parent[a]) return a;
        return (parent[a] = find_set(parent[a]));
    }
 
    void union_set(int a, int b) // join a's and b's components
    {
        int st_a {find_set(a)};
        int st_b {find_set(b)};
        if (st_a != st_b) {
            if (sz[st_a] < sz[st_b])
                swap(st_a, st_b);
            parent[st_b] = st_a;
            sz[st_a] += sz[st_b];
            count_blacks[st_a] += count_blacks[st_b];
        }
    }
 
    vector<int> parent;
    vector<int> sz;
    vector<int> count_blacks;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int q; cin >> q;

    DSU dsu(n);
    vector<bool> colors(n+1, false);

    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int u, v; cin >> u >> v;
            dsu.union_set(u, v);
        }
        else if (x == 2) {
            int u; cin >> u;
            int parent {dsu.find_set(u)};
            if (colors[u]) { // was black
                --dsu.count_blacks[parent];
                colors[u] = false;
            }
            else { // was white
                ++dsu.count_blacks[parent];
                colors[u] = true;
            }
        }
        else {
            int u; cin >> u;
            if (dsu.count_blacks[dsu.find_set(u)] > 0) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}

