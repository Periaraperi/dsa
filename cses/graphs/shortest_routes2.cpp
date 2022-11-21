#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q; cin >> n >> m >> q;
    vector<vector<long long>> graph(n,vector<long long>(n,numeric_limits<long long>::max()));
    for (int i=0; i<n; ++i) graph[i][i] = 0;
    for (int i=0; i<m; ++i) {
        long long a,b,c; cin >> a >> b >> c;
        --a; --b;
        graph[a][b] = min(graph[a][b],c);
        graph[b][a] = min(graph[a][b],c);
    }

    vector<vector<long long>> dis(n,vector<long long>(n,numeric_limits<long long>::max()));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i==j) dis[i][j] = 0;
            else if (graph[i][j]!=numeric_limits<long long>::max()) dis[i][j] = graph[i][j];
        }
    }
    
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (dis[i][k]<numeric_limits<long long>::max() && dis[k][j]<numeric_limits<long long>::max())
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    while (q--) {
        int a,b; cin >> a >> b;
        --a; --b;
        cout << ((dis[a][b]==numeric_limits<long long>::max()) ? -1 : dis[a][b]) << '\n';
    }

    return 0;
}

