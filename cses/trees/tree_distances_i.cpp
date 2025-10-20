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
    
    int x {}, y {}; // any diameter endpoints
    struct info {
        int v {};
        int d {};
    };

    // two passes
    {
        auto bfs = [n, &tree](int start) {
            queue<info> q;
            vector<bool> vis(n, false);
            q.push({start, 0});
            int endpoint {};
            while (!q.empty()) {
                const auto [v, d] {q.front()};
                q.pop();
                vis[v] = true;
                for (const auto& u:tree[v]) {
                    if (!vis[u]) {
                        q.push({u, d+1});
                        endpoint = u;
                    }
                }
            }
            return endpoint;
        };
        x = bfs(0);
        y = bfs(x);
    }

    auto bfs = [n, &tree](int start, vector<int>& dis) {
        queue<info> q;
        vector<bool> vis(n, false);
        q.push({start, 0});
        while (!q.empty()) {
            const auto [v, d] {q.front()};
            q.pop();
            vis[v] = true;
            for (const auto& u:tree[v]) {
                if (!vis[u]) {
                    q.push({u, d+1});
                    dis[u] = d+1;
                }
            }
        }
    };
    vector<int> dis_from_x(n, 0);
    vector<int> dis_from_y(n, 0);
    bfs(x, dis_from_x);
    bfs(y, dis_from_y);

    for (int i{}; i<n; ++i) {
        cout << max(dis_from_x[i], dis_from_y[i]) << " ";
    }
    cout << '\n';

    return 0;
}

