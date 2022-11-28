#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& top_ordering)
{
    if (vis[v]) return;
    vis[v] = true;
    for (auto& u:graph[v])
        dfs(u,graph,vis,top_ordering);
    top_ordering.push_back(v);
}

void top_sort(vector<vector<int>>& graph, vector<int>& top_ordering)
{
    int n = (int)graph.size();
    vector<bool> vis(n,false);
    dfs(0,graph,vis,top_ordering);
    reverse(top_ordering.begin(),top_ordering.end());
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        graph[--a].push_back(--b);
    }
    vector<int> top_ordering;
    top_ordering.reserve(n);
    top_sort(graph,top_ordering);

    long long mod = 1e9 + 7;
    vector<long long> dp(n,0);
    dp[0] = 1;

    for (auto& v:top_ordering) {
        for (auto& u:graph[v]) {
            dp[u] += dp[v];
            dp[u] %= mod;
        }
    }
    cout << dp[n-1] << '\n';
    
    return 0;
}