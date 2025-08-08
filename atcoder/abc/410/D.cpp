#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;

struct Node {
    int v{};
    int w{};
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<Node>> graph(n);

    int max_w {};
    for (int i{}; i<m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        graph[a].emplace_back(Node{b, c});
        max_w = max(max_w, c);
    }

    auto number_of_bits = [](int x) {
        int k{};
        while (x > 0) {
            x /= 2;
            ++k;
        }
        return k;
    };

    int max_xor {(1<<(number_of_bits(max_w)))};
    vector<vector<bool>> vis(n, vector<bool>(max_xor+1, false));

    queue<Node> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto curr {q.front()};
        q.pop();

        if (vis[curr.v][curr.w]) continue;
        vis[curr.v][curr.w] = true;

        for (const auto& node:graph[curr.v]) {
            if (!vis[node.v][node.w^curr.w]) {
                q.push({node.v, node.w^curr.w});
            }
        }
    }

    int ans {-1};
    for (int i{}; i<=max_xor; ++i) {
        if (vis[n-1][i]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}

