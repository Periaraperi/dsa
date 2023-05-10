#include <bits/stdc++.h>
 
using namespace std;
 
// returns start of cycle
int dfs_cycle(int v, const vector<vector<int>>& graph,
              vector<int>& color)
{
    color[v] = 1;
    int start = -1;
    for (auto u:graph[v]) {
        if (color[u]==0) {
            start = dfs_cycle(u,graph,color);
        } else if (color[u]==1) { // cycle found, start == u
            start = u;
        }
    }
    color[v] = 2;
    return start;
}

void get_cycles(vector<vector<int>>& cycles,
                const vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> color(n);
    for (int i=0; i<n; ++i) {
        if (color[i]==0) {
            int cycle_start = dfs_cycle(i,graph,color);

            // push cycle
            int v = cycle_start;
            if (v!=-1) {
                vector<int> cycle;
                while (graph[v][0]!=cycle_start) {
                    cycle.push_back(v);
                    v = graph[v][0];
                }
                cycle.push_back(v); // last node in cycle
                cycles.push_back(cycle);
            }
        }
    }
}

// dis[b] is always smaller if this function is called
int lca(int a, int b, const vector<vector<int>>& jump,
                      const vector<int>& dis)
{
    auto d = dis[a]-dis[b];
    for (int i=30; i>=0; --i) {
        if ((1<<i)<=d) {
            a = jump[i][a];
            d -= (1<<i);
        } 
    }
    
    if (a==b) return b;
    
    for (int i=30; i>=0; --i) {
        if ((1<<i)<=dis[a]) {
            if (jump[i][a]!=jump[i][b]) {
                a = jump[i][a];
                b = jump[i][b];
            }
        }
    }
    return jump[0][a];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vector<vector<int>> graph(n);
    vector<vector<int>> rev_graph(n);
    vector<int> in_degree(n);
    vector<vector<int>> jump(31,vector<int>(n));
    for (int i=0; i<n; ++i) {
        int a; cin >> a; --a;
        graph[i].push_back(a); // graph is functional
        rev_graph[a].push_back(i);
        jump[0][i] = a;
        ++in_degree[a];
    }

    // binary lifting here
    for (int i=1; i<=30; ++i) {
        for (int j=0; j<n; ++j) {
            jump[i][j] = jump[i-1][jump[i-1][j]];
        }
    }
    
    vector<vector<int>> cycles;
    get_cycles(cycles,graph);
    vector<bool> inside_cycle(n);
    vector<int> cycle_len(n);
    vector<int> cycle_rep(n,-1);
    for (const auto& c:cycles) {
        for (auto u:c) {
            inside_cycle[u] = true;
            cycle_len[u] = c.size();
            cycle_rep[u] = c[0];
        }
    }
    
    // if cycle , dis[v] = dis from start of cycle to v
    // if outside cycle, i.e in tree, dis[v] = dis from root to v
    vector<int> dis(n,-1);
    
    // cycle distances
    for (int i=0; i<cycles.size(); ++i) {
        int len = 0;
        for (auto v:cycles[i]) {
            dis[v] = len;
            ++len;
        }
    }

    // tree distances
    // tree roots are part of cycle, they have in_degree more then 1 inside cycle
    vector<bool> inside_tree(n);
    vector<int> root(n,-1);
    vector<int> roots;
    for (const auto& c:cycles) {
        for (auto v:c) {
            if (in_degree[v]>1) {
                roots.push_back(v);
            }
        }
    }

    for (auto r:roots) {
        queue<int> q;
        q.push(r);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto u:rev_graph[p]) {
                if (inside_cycle[u]) continue;
                if (p==r) {
                    dis[u] = 1;
                } else {
                    dis[u] = dis[p]+1;
                }
                root[u] = r;
                inside_tree[u] = true;
                q.push(u);
            }
        }
    }

    while (q--) {
        int a,b; cin >> a >> b;
        --a; --b;
        if (a==b) {
            cout << "0\n";
            continue;
        }
        int total_dis = -1;
        if (inside_cycle[a]&&inside_cycle[b]) { // both inside cycle
            if (cycle_rep[a]==cycle_rep[b]) { // same cycle
                if (dis[a]<dis[b]) {
                    total_dis = dis[b]-dis[a];
                } else if (dis[a]>dis[b]) {
                    total_dis = cycle_len[a]-(dis[a]-dis[b]);
                } 
            }
        } else if (inside_tree[a]&&inside_tree[b]) { // both inside tree
            if (root[a]==root[b]) { // same tree
                if (dis[a]>dis[b] && lca(a,b,jump,dis)==b) {
                    total_dis = dis[a]-dis[b];
                }
            }
        } else {
            if (inside_tree[a]&&inside_cycle[b]&&cycle_rep[b]==cycle_rep[root[a]]) {
                total_dis = dis[a];
                a = root[a];
                if (dis[a]<dis[b]) {
                    total_dis += dis[b]-dis[a];
                } else if (dis[a]>dis[b]) {
                    total_dis += (cycle_len[a]-(dis[a]-dis[b]));
                }
            }
        }
        cout << total_dis << '\n';
    }
    return 0;
}
