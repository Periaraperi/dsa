#include <bits/stdc++.h>
 
using namespace std;
 
// educational: minimum spanning trees, with kruskals

struct DSU {
    DSU(int n)
        :parent(n+1), sz(n+1)
    {
        for (int i=1; i<=n; ++i)
            make_set(i);
    }
    
    void make_set(int a)
    {
        parent[a] = a;
        sz[a] = 1;
    }

    int find_set(int a)
    {
        if (a==parent[a]) return a;
        return (parent[a] = find_set(parent[a]));
    }

    void union_set(int a, int b)
    {
        int st_a = find_set(a);
        int st_b = find_set(b);
        if (st_a!=st_b) {
            if (sz[st_a]<sz[st_b])
                swap(st_a,st_b);
            parent[st_b] = st_a;
            sz[st_a] += sz[st_b];
        }
    }

    vector<int> parent;
    vector<int> sz;
};

struct node {
    int from,to;
    int64_t cost;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<node> graph(m);
    for (int i=0; i<m; ++i) {
        auto& v = graph[i];
        cin >> v.from >> v.to >> v.cost;
        --v.from; -- v.to;
    }
    
    auto by_cost = [](const node& a, const node& b) -> bool {
        return a.cost<b.cost;
    };
    sort(graph.begin(),graph.end(),by_cost);

    DSU dsu(n);
    int64_t tot = 0;
    for (int i=0; i<m; ++i) {
        auto& v = graph[i];
        if (dsu.find_set(v.from+1)!=dsu.find_set(v.to+1)) {
            tot += v.cost;
            dsu.union_set(v.from+1,v.to+1);
        }
    }
    
    bool ok = true;
    for (int i=2; i<=n; ++i) {
        if (dsu.find_set(i)!=dsu.find_set(i-1)) {
            ok = false;
            break;
        }
    }
    if (ok) cout << tot << '\n';
    else    cout << "IMPOSSIBLE\n";

    return 0;
}

