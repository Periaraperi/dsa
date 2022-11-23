#include <bits/stdc++.h>
 
using namespace std;
 
struct Edge {
    int from,to;
    long long cost;
};

long long INF;

void bellman_ford(const vector<Edge>& edges, int n)
{
    vector<long long> dis(n,INF);
    dis[0] = 0;
    vector<int> parent(n);
    
    int x = -1;
    for (int i=0; i<n; ++i) {
        x = -1;
        for (auto& e:edges) {
            if (dis[e.from]+e.cost<dis[e.to]) {
                dis[e.to] = dis[e.from]+e.cost;
                parent[e.to] = e.from;
                x = e.to;
            }
        }
    } 

    if (x==-1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> cycle;
        for (int i=0; i<n; ++i) x = parent[x];
        for (int i=x; ; i=parent[i]) {
            cycle.push_back(i);
            if (i==x && cycle.size()>1) break;
        }
        for (int i=(int)cycle.size()-1; i>=0; --i) {
            cout << cycle[i]+1 << " ";
        }
        cout << '\n';
    }

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<Edge> edges(m);
    long long mx_cost = std::numeric_limits<long long>::min();
    for (int i=0; i<m; ++i) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        edges[i] = {--a,--b,c};
        mx_cost = max(mx_cost,c);
    }
    INF = mx_cost+1;
    
    bellman_ford(edges,n);

    return 0;
}

