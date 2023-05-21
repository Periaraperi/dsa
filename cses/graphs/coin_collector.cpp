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
    vector<int> coins(n);
    for (int i=0; i<n; ++i) 
        cin >> coins[i];
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
    for (auto v:exit_time_order) {
        if (!vis[v]) {
            vector<int> comp;
            dfs2(v,rev_g,vis,comp);
            scc.push_back(comp);
        }
    }
    
    vector<int> who(n);
    vector<int> reps;
    vector<int64_t> total_coins(n,-1);
    for (auto c:scc) {
        int rep = c[0];
        reps.push_back(rep);
        total_coins[rep] = 0;
        for (auto v:c) {
            who[v] = rep;
            total_coins[rep] += coins[v];
        }
    }

    vector<vector<int>> cond(n);
    for (int i=0; i<n; ++i) {
        for (auto u:g[i]) {
            if (who[i]!=who[u]) {
                cond[who[i]].push_back(who[u]);
            }
        }
    }

    vector<int64_t> dp(n);
    vector<int> top_order;
    for (int i=0; i<n; ++i) vis[i] = false;
    for (auto r:reps) {
        if (!vis[r]) {
            dfs1(r,cond,vis,top_order);
        }
    }
    
    reverse(top_order.begin(),top_order.end());
    for (auto v:top_order) {
        if (dp[v]==0) dp[v] = total_coins[v];
        for (auto u:cond[v]) {
            dp[u] = max(dp[u], dp[v]+total_coins[u]);
        }
    }
    int64_t sm = 0;
    for (auto i:dp) sm = max(sm,i);
    cout << sm << '\n';
    return 0;
}
