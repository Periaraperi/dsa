#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    struct node {
        int id{};
        int w{};
    };
    vector<vector<node>> graph(n);
    int mx_cost {};
    vector<int> costs;
    {
        set<int> vis;
        for (int i{}; i<m; ++i) {
            int a, b, c; cin >> a >> b >> c;
            --a; --b;
            mx_cost = max(mx_cost, c);
            vis.insert(c);
            graph[a].emplace_back(node{b, c});
            graph[b].emplace_back(node{a, c});
        }
        for (const auto& i:vis) costs.emplace_back(i);
    }

    int leftmost_set_bit {};
    for (int i{30}; i>=0; --i) {
        if (((1<<i)&mx_cost)>0) {
            leftmost_set_bit = i;
            break;
        }
    }

    int ans {};
    {
        unordered_map<int, int> marked; marked.reserve(1<<20);
        for (const auto& c:costs) {
            marked.insert({c, 0});
        }
        vector<bool> vis(n, false);
        queue<int> q;

        for (int i{leftmost_set_bit}; i>=0; --i) {
            for (const auto& c:costs) {
                if (((1<<i)&c)>0 && marked[c]!=2) {
                    marked[c] = 1;
                }
            }

            for (int j{}; j<static_cast<int>(vis.size()); ++j) vis[j] = false;
            q.push(0);
            while (!q.empty()) {
                const auto v {q.front()};
                q.pop();
                if (vis[v]) continue;
                vis[v] = true;
                for (const auto& u:graph[v]) {
                    if (vis[u.id] || marked[u.w]!=0) continue;
                    q.push(u.id);
                }
            }
            if (!vis[n-1]) { // unmark
                for (const auto& c:costs) {
                    if (((1<<i)&c)>0 && marked[c]!=2) {
                        marked[c] = 0;
                    }
                }
                ans |= (1<<i);
            }
            else {
                for (const auto& c:costs) {
                    if (((1<<i)&c)>0) {
                        marked[c] = 2;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

