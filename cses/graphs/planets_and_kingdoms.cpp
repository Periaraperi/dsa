#include <bits/stdc++.h>
 
using namespace std;

void dfs1(int v, const vector<vector<int>>& g,
          vector<bool>& vis, vector<int>& order)
{
    if (vis[v]) return;
    vis[v] = true;
    for (auto u:g[v])
        dfs1(u,g,vis,order);
    order.push_back(v);
}

void dfs2(int v, const vector<vector<int>>& rev_g,
          vector<bool>& vis, vector<int>& comp)
{
    if (vis[v]) return;
    vis[v] = true;
    comp.push_back(v);
    for (auto u:rev_g[v])
        dfs1(u,rev_g,vis,comp);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> rev_g(n);
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }

    vector<bool> vis(n);
    vector<int> exit_time_order(n);
    for (int v=0; v<n; ++v) {
        if (!vis[v])
            dfs1(v,g,vis,exit_time_order);
    }
    
    reverse(exit_time_order.begin(),exit_time_order.end());
    for (int i=0; i<n; ++i) vis[i] = false;

    vector<vector<int>> scc;
    vector<int> who(n);
    for (auto v:exit_time_order) {
        if (!vis[v]) {
            vector<int> comp;
            dfs2(v,rev_g,vis,comp);
            scc.push_back(comp);
        }
    }
    int cnt = 1;
    for (auto c:scc) {
        for (auto v:c) {
            who[v] = cnt;
        }
        ++cnt;
    }
    cout << scc.size() << '\n';
    for (int i=0; i<n; ++i) {
        cout << who[i] << " ";
    }
    cout << '\n';
    return 0;
}

