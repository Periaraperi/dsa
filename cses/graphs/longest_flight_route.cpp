#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& top_ordering)
{
    if (vis[v]) return;
    vis[v] = true;
    for (auto& u:graph[v]) dfs(u,graph,vis,top_ordering);
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        graph[--a].push_back(--b);
    }

    vector<int> top_ordering;
    top_ordering.reserve(n);
    top_sort(graph,top_ordering);

    vector<int> parent(n,-1);
    vector<int> dis(n,0);
    for (auto& v:top_ordering) {
        for (auto& u:graph[v]) {
            if (dis[v]-1<dis[u]) {
                dis[u] = dis[v]-1;
                parent[u] = v;
            }
        }
    }
    
    if (dis[n-1]==0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    for (int v=n-1; v!=-1; v=parent[v]) {
        path.push_back(v+1);
    }
    reverse(path.begin(),path.end());
    cout << path.size() << '\n';
    for (auto& i:path) cout << i << " ";
    cout << '\n';

    return 0;
}