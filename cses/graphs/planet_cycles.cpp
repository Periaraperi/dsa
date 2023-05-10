#include <bits/stdc++.h>
 
using namespace std;

// get start of cycle
int dfs(int v, const vector<int>& f_graph, vector<int>& color)
{
    color[v] = 1;
    int start = -1;

    int to = f_graph[v];
    if (color[to]==0) {
        start = dfs(to,f_graph,color);
    } else if (color[to]==1) {
        start = to;
    }

    color[v] = 2;
    return start;
}

vector<vector<int>> get_cycles(const vector<int>& f_graph)
{
    int n = f_graph.size();
    vector<int> color(n);
    vector<vector<int>> cycles;

    for (int i=0; i<n; ++i) {
        if (color[i]==0) {
            int cycle_start = dfs(i,f_graph,color);
            if (cycle_start!=-1) {
                vector<int> cycle;
                int v = cycle_start;
                while (f_graph[v]!=cycle_start) {
                    cycle.push_back(v);
                    v = f_graph[v];
                }
                cycle.push_back(v);
                cycles.push_back(cycle);
            }
        }
    }
    return cycles;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> f_graph(n);  
    vector<int> in_degree(n);
    vector<vector<int>> rev_graph(n);
    for (int i=0; i<n; ++i) {
        int a; cin >> a; --a;
        f_graph[i] = a;
        ++in_degree[a];
        rev_graph[a].push_back(i);
    }

    auto cycles = get_cycles(f_graph);
    vector<bool> in_cycle(n);
    vector<int> cycle_len(n);
    for (const auto& c:cycles) {
        for (auto v:c) {
            in_cycle[v] = true; 
            cycle_len[v] = c.size();
        }
    }

    vector<int> root(n,-1);
    vector<int> roots;
    for (int i=0; i<cycles.size(); ++i) {
        for (auto v:cycles[i]) {
            if (in_degree[v]>1)
                roots.push_back(v);
        }
    }

    vector<int> dis(n,-1); // dis to root for nodes outside of cycle
    for (auto r:roots) {
        root[r] = r;
        queue<int> q;
        q.push(r);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto u:rev_graph[v]) {
                if (in_cycle[u]) continue;
                if (v==r) {
                    dis[u] = 1;
                } else {
                    dis[u] = dis[v]+1;
                }
                root[u] = r;
                q.push(u);
            }
        }
    }

    for (int i=0; i<n; ++i) {
        if (in_cycle[i]) {
            cout << cycle_len[i] << " ";
        } else {
            cout << dis[i]+cycle_len[root[i]] << " ";
        }
    }
    cout << '\n';

    return 0;
}

