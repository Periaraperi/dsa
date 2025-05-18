#include <bits/stdc++.h>
 
using namespace std;

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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; // cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<pair<int,int>> edges(m);
        DSU comps(n);
        for (int i=0; i<m; ++i) {
            cin >> edges[i].first >> edges[i].second;
            comps.union_set(edges[i].first, edges[i].second);
        }
        set<pair<int,int>> st;
        int k; cin >> k;
        for (int i=0; i<k; ++i) {
            int a,b; cin >> a >> b;
            int pa = comps.find_set(a);
            int pb = comps.find_set(b);
            st.insert({pa,pb});
            st.insert({pb,pa});
        }

        bool ok = true;
        for (auto [u,v]:edges) {
            u = comps.find_set(u);
            v = comps.find_set(v);
            if (st.find({u,v})!=st.end() || st.find({v,u})!=st.end()) {
                ok = false;
                break;
            }
        }
        int qq; cin >> qq;
        while (qq--) {
            int a,b; cin >> a >> b;
            if (!ok) {
                cout << "No\n";
                continue;
            }
            int pa = comps.find_set(a);
            int pb = comps.find_set(b);
            if (st.find({pa,pb})!=st.end() || st.find({pb,pa})!=st.end()) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}

