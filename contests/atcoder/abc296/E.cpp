#include <bits/stdc++.h>
 
using namespace std;

bool dfs(int v, const vector<vector<int>>& graph, 
                vector<int>& color,
                vector<int>& fix,
                int& cycle_start)
{
    color[v] = 1;
    for (auto u:graph[v]) {
        if (color[u]==0) {
            bool b = dfs(u,graph,color,fix,cycle_start);
            if (b) { // v participates in cycle
                fix[v] = 1;
            }
        } else if (color[u]==1) { // cycle found
            cycle_start = u;
            fix[v] = 1;
        }
    }

    color[v] = 2;
    if (v==cycle_start || cycle_start==-1) {
        cycle_start = -1;
        return false;
    }
    return true;
}

void cycles(int n, const vector<vector<int>>& graph, vector<int>& fix)
{
    vector<int> color(n+1);
    for (int i=1; i<=n; ++i) {
        if (color[i]==0) {
            int start = -1;
            dfs(i,graph,color,fix,start);
        }
    }
    // if we have some uncertain nodes after cycle finding
    // those nodes will be bad
    for (int i=1; i<=n; ++i) 
        if (fix[i]==0) fix[i] = -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;

    while(t--) {
        int n; cin >> n; 
        vector<int> v(n+1);
        vector<int> fix(n+1,-1);
        vector<vector<int>> graph(n+1);
        for (int i=1; i<=n; ++i) {
            int a; cin >> a;
            if (fix[a]==-1) 
                fix[a] = 0;
            if (i==a)
                fix[a] = 1;
            graph[i].push_back(a);
        }
        // there is at most 1 cycle in each component
        // all elements participating in cycle or the ones that are hooks are good
        // ans = number of such elements
        int ans = 0;
        cycles(n,graph,fix);
        for (int i=1; i<=n; ++i)
            if (fix[i]==1) ++ans;
        cout << ans << '\n';
    }
    return 0;
}

