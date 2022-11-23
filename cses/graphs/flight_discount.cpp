#include <bits/stdc++.h>
 
using namespace std;


long long dijkstra(const vector<vector<pair<int,long long>>>& graph)
{
    int n = (int)graph.size();
    long long INF = numeric_limits<long long>::max();
    vector<long long> dis[2]; // 0 means ticket not used, 1 means used
    dis[0] = vector<long long>(n,INF);
    dis[1] = vector<long long>(n,INF);
    dis[0][0] = dis[1][0] = 0;

    struct Vertex {
        Vertex(int a, long long b, bool u) 
            :node_id(a), weight(b), used(u) {}
        int node_id;
        long long weight;
        bool used;
    };
    auto comp = [](const Vertex& a, const Vertex& b) {
        return a.weight>b.weight;
    };
    priority_queue<Vertex,vector<Vertex>,decltype(comp)> pq(comp);

    pq.emplace(0,0,false);
    
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        if (v.weight!=dis[v.used][v.node_id])
            continue;

        for (auto& u:graph[v.node_id]) {
            if (!v.used) { // try using ticket
                long long new_dis = dis[0][v.node_id] + u.second/2;
                if (new_dis<dis[1][u.first]) {
                    dis[1][u.first] = new_dis;
                    pq.emplace(u.first,new_dis,true);
                }
            }
            long long new_dis = dis[v.used][v.node_id] + u.second;
            if (new_dis<dis[v.used][u.first]) {
                dis[v.used][u.first] = new_dis;
                pq.emplace(u.first,new_dis,v.used);
            }
        }
    }
    
    return dis[1][n-1];
} 

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<vector<pair<int,long long>>> graph(n,vector<pair<int,long long>>());
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        long long c; cin >> c;
        graph[a].push_back({b,c});
    }

    cout << dijkstra(graph);

    return 0;
}

