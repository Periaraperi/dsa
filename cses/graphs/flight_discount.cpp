#include <bits/stdc++.h>
 
using namespace std;

// solution with dp
long long dijkstra_solution_dp(const vector<vector<pair<int,long long>>>& graph)
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

// default dijkstra, need for solution with reversed graph
void regular_dijkstra(const vector<vector<pair<int,long long>>>& graph,
                      vector<long long>& min_dis, int start)
{
    const long long INF = numeric_limits<long long>::max();
    for (auto& d:min_dis) d = INF;
    min_dis[start] = 0;
    
    vector<bool> vis((int)graph.size(),false);

    auto comp = [](const pair<int,long long>& a, const pair<int,long long>& b) {
        return a.second>b.second;
    };
    priority_queue<pair<int,long long>,vector<pair<int,long long>>,decltype(comp)> pq(comp);
    pq.push({start,0});

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        if (vis[v.first]) continue;
        vis[v.first] = true;
        for (auto& u:graph[v.first]) {
            if (vis[u.first]) continue;
            long long new_dis = min_dis[v.first] + u.second;
            if (new_dis<min_dis[u.first]) {
                min_dis[u.first] = new_dis;
                pq.push({u.first,new_dis});
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<vector<pair<int,long long>>> graph(n,vector<pair<int,long long>>());
    // we need reveresed graph for second solution
    vector<vector<pair<int, long long>>> reversed_graph(n,vector<pair<int,long long>>());
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        long long c; cin >> c;
        graph[a].push_back({b,c});
        reversed_graph[b].push_back({a,c});
    }
    
    // soultion 1
    //cout << dijkstra_solution_dp(graph);
    
    // solution 2
    vector<long long> min_dis1(n); // stores min distance from 1 to every other node
    regular_dijkstra(graph,min_dis1,0);
    vector<long long> min_dis2(n); // stores min distance from every vertex to n
    regular_dijkstra(reversed_graph,min_dis2,n-1);
    
    // traverse the graph and try to use ticket
    // optimal answer is maximum between:
    // min dis from (1 to i) + (discount from i to next node) + min dis from (next node to n)
    // check all i
    long long min_cost = min_dis1[n-1];
    long long INF = numeric_limits<long long>::max();
    for (int v=0; v<n; ++v) {
        for (auto& u:graph[v]) {
            if (min_dis1[v]!=INF && min_dis2[u.first]!=INF)
                min_cost = min(min_cost,min_dis1[v]+(u.second/2)+min_dis2[u.first]);
        }
    }
    cout << min_cost << '\n';

    return 0;
}

