#include <bits/stdc++.h>
 
using namespace std;

// kosaraju

void dfs1(int v, const vector<vector<int>>& g, vector<bool>& vis, vector<int>& order)
{
    if (vis[v]) return;
    vis[v] = true;
    for (auto u:g[v]) dfs1(u,g,vis,order);
    order.push_back(v);
}

void dfs2(int v, const vector<vector<int>>& rev_g, vector<bool>& vis, vector<int>& comp)
{
    if (vis[v]) return;
    vis[v] = true;
    comp.push_back(v);
    for (auto u:rev_g[v]) dfs2(u,rev_g,vis,comp);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<vector<int>> rev_graph(n);
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    vector<bool> vis(n);
    vector<int> exit_time_order;
    for (int i=0; i<n; ++i) {
        if (!vis[i]) {
            dfs1(i,graph,vis,exit_time_order);
        }
    }
    
    reverse(exit_time_order.begin(),exit_time_order.end());
    for (int i=0; i<n; ++i) vis[i] = false;
    
    vector<vector<int>> scc;
    for (auto v:exit_time_order) {
        if (!vis[v]) {
            vector<int> comp;
            dfs2(v,rev_graph,vis,comp);
            scc.push_back(comp);
        }
    }
    if (scc.size()==1) cout << "YES\n";
    else {
        vector<int> representative(n);
        vector<int> reps;
        for (auto comp:scc) {
            auto rep = comp.front();
            reps.push_back(rep);
            for (auto v:comp) {
                representative[v] = rep;
            }
        }

        int x=-1,y=-1;
        bool found = false;
        for (int v=0; v<n; ++v) {
            for (auto u:graph[v]) {
                if (representative[u]!=representative[v]) {
                    x = u;
                    y = v;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        cout << "NO\n";
        if (x==-1 && y==-1) {
            cout << scc[0][0]+1 << " " << scc[1][0]+1;
        } else {
            cout << x+1 << " " << y+1;
        }
        cout << '\n';
    }

    return 0;
}

