#include <iostream>
#include <set>
#include <vector>
 
using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& vis)
{
    if (vis[v]) return;
    vis[v] = true;
    for (const auto& u:graph[v]) {
        dfs(u, graph, vis);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N);
    set<pair<int, int>> vis;
    for (int i{}; i<M; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        if (vis.find({a,b}) != vis.end()) {
            continue;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
        vis.insert({a, b});
    }
    
    bool ok {true};
    for (int i{}; i<N; ++i) {
        if (graph[i].size() != 2) {
            ok = false;
            break;
        }
    }

    int comps{};
    vector<bool> vis2(N, false);
    for (int i{}; i<N; ++i) {
        if (!vis2[i]) {
            dfs(i, graph, vis2);
            ++comps;
        }
    }

    if (ok && comps == 1) cout << "Yes\n";
    else    cout << "No\n";

    return 0;
}

