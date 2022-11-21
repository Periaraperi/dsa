#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * problem about bipartite graph. coloring
 */

const int N = 1e5 + 1;
vector<int> graph[N];
int color[N];
bool vis[N];
int n,m;

int BFS(int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    color[i] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto v:graph[curr])
        {
            if(vis[v] && color[v]==color[curr]) return -1;
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
                if(color[curr]==0) color[v] = 1;
                else color[v] = 0;
            }
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; ++i)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; ++i)
    {
        if(!vis[i])
        {
            if(BFS(i)==-1)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i=1; i<=n; ++i)
        cout << color[i]+1 << " ";
}
