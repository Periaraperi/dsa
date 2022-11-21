#include <bits/stdc++.h>
 
using namespace std;
 
struct Edge {
    int a,b;
    long long w;
};

// check if last node is reachable from v
void dfs(int v, const vector<vector<pair<int,long long>>>& graph, vector<bool>& vis)
{
    vis[v] = true;
    for (auto u:graph[v]) {
        if (!vis[u.first]) 
            dfs(u.first,graph,vis);
    }
}

bool dfs_cycle(int v, long long sm, const vector<vector<pair<int,long long>>>& graph, vector<int>& color)
{
    color[v] = 1;
    for (auto u:graph[v]) {
        if (color[u.first]==0) {
            if (dfs_cycle(u.first,sm+u.second,graph,color)) {
                return true;
            }
        } else if (color[u.first]==1) {
            if (sm+u.second>0) { // positive cycle found
                // check if endpoint is reachable from this cycle
                vector<bool> vis(graph.size(),false);
                dfs(v,graph,vis);
                if (vis[(int)graph.size()-1] && color[0]==1) return true;
            }
        }
    }
    
    color[v] = 2;
    return false;
}


bool positive_cycle(const vector<vector<pair<int,long long>>>& graph)
{
    int n = (int) graph.size();
    for (int i=0; i<n; ++i) {
        vector<int> color(n,0);
        if (dfs_cycle(i,0,graph,color)) return true;
    }
    return false; 
}

long long bellman_ford(const vector<Edge>& edges, int n, int m)
{
    const long long INF = numeric_limits<long long>::max();
    vector<long long> dis(n,INF); 
    dis[n-1] = 0;
    
    for (;;) {
        bool changed = false;
        for (int i=0; i<m; ++i) {
            if (dis[edges[i].a]<INF) {
                if (dis[edges[i].a]+edges[i].w<dis[edges[i].b]) {
                    dis[edges[i].b] = dis[edges[i].a]+edges[i].w;
                    changed = true;
                }
            }
        }
        if (!changed)
            break;
    }
    return dis[0];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i=0; i<m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        --edges[i].a;
        --edges[i].b;
    }
    vector<vector<pair<int,long long>>> graph(n,vector<pair<int,long long>>());
    for (auto& e:edges) {
        graph[e.a].push_back({e.b,e.w});
    }

    if (positive_cycle(graph))
        cout << -1 << '\n';
    else {
        for (auto &e:edges) {
            swap(e.a,e.b);
            e.w *= (-1);
        }
        cout << -bellman_ford(edges,n,m);
    }
      
    return 0;
}

