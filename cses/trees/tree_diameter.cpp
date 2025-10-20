#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i{}; i<n-1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    struct info {
        int u {};
        int d {};
    };
    vector<bool> vis(n, false);
    queue<info> q;
    q.push({0, 0});

    int x {};
    while (!q.empty()) {
        const auto [v, d] {q.front()};
        q.pop();
        vis[v] = true;
        for (const auto& u:tree[v]) {
            if (!vis[u]) {
                q.push({u, d+1});
                x = u;
            }
        }
    }
    vis = vector<bool>(n, false);
    q.push({x, 0});
    int dis {};
    while (!q.empty()) {
        const auto [v, d] {q.front()};
        q.pop();
        vis[v] = true;
        for (const auto& u:tree[v]) {
            if (!vis[u]) {
                q.push({u, d+1});
                dis = d+1;
            }
        }
    }
    cout << dis << '\n';
    return 0;
}

