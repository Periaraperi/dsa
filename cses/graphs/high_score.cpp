#include <bits/stdc++.h>
 
using namespace std;
 
struct Edge {
    int a,b;
    long long w;
};

long long bellman_ford(const vector<Edge>& edges, int n, int m)
{
    const long long INF = numeric_limits<long long>::max();
    vector<long long> dis(n,INF); 
    dis[0] = 0;
    
    for (int j=0; j<n-1; ++j) { // at most n-1 iterations needed
        bool changed = 0;
        for (int i=0; i<m; ++i) {
            if (dis[edges[i].a]<INF) {
                if (dis[edges[i].a]+edges[i].w<dis[edges[i].b]) {
                    dis[edges[i].b] = dis[edges[i].a]+edges[i].w;
                    changed = true; // at least one change is made
                }
            }
        }
        if (!changed) { // already have best answers, no need for rest iterations
            return -dis[n-1];
        }
    }
    for (int j=0; j<n-1; ++j) {
        for (int i=0; i<m; ++i) { // check for negative cycle
            if (dis[edges[i].a]==numeric_limits<long long>::min()) {
                dis[edges[i].b] = numeric_limits<long long>::min();
                continue;
            }
            if (dis[edges[i].a]<INF) {
                if (dis[edges[i].a]+edges[i].w<dis[edges[i].b]) {
                    dis[edges[i].b] = numeric_limits<long long>::min();
                }
            }
        }
    }
    return (dis[n-1]==numeric_limits<long long>::min()) ? -1 : -dis[n-1];
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
        edges[i].w *= (-1);
    }

    cout << bellman_ford(edges,n,m);
      
    return 0;
}

