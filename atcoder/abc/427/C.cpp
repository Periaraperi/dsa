#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& vis, vector<int>& component)
{
    if (vis[v]) return;
    component.emplace_back(v);
    vis[v] = true;
    for (const auto& u:graph[v]) {
        dfs(u, graph, vis, component);
    }
}

vector<vector<int>> get_components(const vector<vector<int>>& graph, int n)
{
    vector<vector<int>> components;
    vector<bool> vis(n, false);
    for (int i{}; i<n; ++i) {
        if (!vis[i]) {
            components.emplace_back();
            dfs(i, graph, vis, components.back());
        }
    }
    return components;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    auto components {get_components(graph, n)};

    struct node {
        int u {};
        int c {};
    };
    constexpr int INF {numeric_limits<int>::max()};

    int ans {};
    for (const auto& c:components) {
        int N {static_cast<int>(c.size())};
        int mn {INF};
        for (int i{}; i<(1<<N); ++i) {
            vector<int> color(n, 0);
            for (int j{}; j<N; ++j) {
                if ((i & (1<<j)) != 0) {
                    color[c[j]] = 1;
                }
            }

            int cnt {};
            for (int j{}; j<N; ++j) {
                for (const auto& u:graph[c[j]]) {
                    if (color[c[j]] == color[u]) {
                        ++cnt;
                    }
                }
            }
            mn = min(mn, cnt);
        }
        if (mn != INF)
            ans += mn;
    }
    cout << ans/2 << '\n';

    return 0;
}

