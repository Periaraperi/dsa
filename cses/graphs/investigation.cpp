#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int64_t MOD = 1e9 + 7;
constexpr int64_t INF = 1e18;
struct node {
    int vert;
    int64_t cost;
};

void dijkstra(int start, const vector<vector<node>>& graph, 
                         vector<int64_t>& dis,
                         vector<int>& cnt_max,
                         vector<int>& cnt_min,
                         vector<int64_t>& paths)
{
    dis[start] = 0;
    cnt_max[start] = 0;
    cnt_min[start] = 0;
    paths[start] = 1;
    
    auto comp = [](const node& a, const node& b) -> bool {
        if (a.cost==b.cost) return a.vert<b.vert;
        return a.cost>b.cost;
    };
    vector<bool> vis(graph.size(),false);
    priority_queue<node,vector<node>,decltype(comp)> pq(comp);
    pq.push({start,0});
    while (!pq.empty()) {
        auto [v,v_cost] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [u,u_cost]:graph[v]) {
            auto new_dis = v_cost + u_cost; // go from v to u
            if (new_dis<dis[u]) {
                dis[u] = new_dis;
                cnt_max[u] = cnt_max[v]+1;
                cnt_min[u] = cnt_min[v]+1;
                paths[u] = paths[v]%MOD;
                pq.push({u,new_dis});
            } else if (new_dis==dis[u]) {
                cnt_max[u] = max(cnt_max[u],cnt_max[v]+1);
                cnt_min[u] = min(cnt_min[u],cnt_min[v]+1);
                paths[u] = (paths[u]+paths[v])%MOD;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<vector<node>> graph(n);
    for (int i=0; i<m; ++i) {
        int a,b,c; cin >> a >> b >> c;
        --a; --b;
        graph[a].push_back({b,c});
    }
    vector<int64_t> dis(n,INF), count_paths(n);
    vector<int> count_max(n), count_min(n);
    dijkstra(0,graph,dis,count_max,count_min,count_paths);
    
    cout << dis[n-1] << " " << count_paths[n-1] << " " << count_min[n-1] << " " << count_max[n-1] <<'\n';

    return 0;
}

