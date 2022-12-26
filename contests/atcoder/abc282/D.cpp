#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> bipartite_matching(const vector<vector<int>>& graph,
                                              vector<int>& color, int start) 
{
    queue<int> q;
    q.push(start);
    color[start] = 1;
    auto p = make_pair(1LL,0LL);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto u:graph[v]) {
            if (color[u]==-1) {
                color[u] = color[v]^1;
                (color[u]==1) ? ++p.first : ++p.second;
                q.push(u);
            } else {
                if (color[v]==color[u]) {
                    return {-1LL,-1LL};
                }
            }
        }
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int i=0; i<m; ++i) {
            int a,b; cin >> a >> b;
            --a; --b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        long long ans = n*(n-1LL)/2LL - m;
        vector<int> color(n,-1);
        bool ok = true;
        for (int i=0; i<n; ++i) {
            if (color[i]==-1) {
                auto p = bipartite_matching(graph,color,i);
                if (p.first==-1) {
                    ok = false;
                    break;
                }
                ans -= (p.first*(p.first-1))/2LL;
                ans -= (p.second*(p.second-1))/2LL;
            }
        }
        if (!ok) {
            cout << "0\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}