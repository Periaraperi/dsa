#include <bits/stdc++.h>
 
using namespace std;

struct Node {
    int to;
    long long w;
};
 
//functor way
struct Compare_Node {
    bool operator()(Node a, Node b) 
    {
        return a.w>b.w;
    }
};

void dijkstra(const vector<vector<Node>>& graph, vector<long long>& dis, int start) 
{
    const long long INF = numeric_limits<long long>::max();
    for (int i=0; i<(int)graph.size(); ++i)
        if (i!=start) dis[i] = INF;

    vector<bool> vis(graph.size(),false);

    auto comp = [](Node a, Node b) {return a.w>b.w;};
    priority_queue<Node,vector<Node>,decltype(comp)> pq(comp);
    pq.push({start,0});
    
    while (!pq.empty()) {
        auto next_best = pq.top();
        pq.pop();
        if (vis[next_best.to]) continue;
        vis[next_best.to] = true;
        for (auto& neighbours:graph[next_best.to]) {
            if (vis[neighbours.to]) continue;

            auto new_dis = dis[next_best.to] + neighbours.w;
            if (new_dis<dis[neighbours.to]) {
                dis[neighbours.to] = new_dis;
                pq.push({neighbours.to,new_dis});
            }
        }
    }

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m; cin >> n >> m;
    vector<vector<Node>> graph(n,vector<Node>());
    for (int i=0; i<m; ++i) {
        int a,b,c; cin >> a >> b >> c;
        --a; --b;
        graph[a].push_back({b,c});
    }

    vector<long long> dis(n,0);
    dijkstra(graph,dis,0);
    for (int i=0; i<n; ++i)
        cout << dis[i] << " ";

    return 0;
}

