#include <bits/stdc++.h>
 
using namespace std;

struct DSU {
    DSU(int n)
        :parent(n+1), sz(n+1), mx_size(1)
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
            mx_size = max(mx_size,sz[st_a]);
        }
    }

    vector<int> parent;
    vector<int> sz;
    int mx_size;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    DSU dsu(n);
    int comp_cnt = n;
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        if (dsu.find_set(a)!=dsu.find_set(b))
            --comp_cnt;
        dsu.union_set(a,b);
        cout << comp_cnt << " " << dsu.mx_size << '\n';
    }

    return 0;
}

