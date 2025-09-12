#include <iostream>
#include <vector>
#include <limits>
#include <queue>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int64_t INF {numeric_limits<int64_t>::max()};

    int n, m;
    int64_t x;
    cin >> n >> m >> x;
    vector<vector<int>> graph(n);
    vector<vector<int>> rev_graph(n);
    for (int i{}; i<m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph[u].emplace_back(v);
        rev_graph[v].emplace_back(u);
    }

    struct node {
        int v;
        int64_t cost;
        int rev_count;
    };

    auto comp = [](const node& a, const node& b) {
        return a.cost > b.cost;
    };
    priority_queue<node, vector<node>, decltype(comp)> pq(comp);
    vector<vector<int64_t>> dis(n, vector<int64_t>(2, INF));
    dis[0][0] = 0;
    dis[0][1] = x;
    pq.push({0, 0, 0});
    pq.push({0, x, 1});

    while (!pq.empty()) {
        const auto [v, c, rev_count] {pq.top()};
        pq.pop();
        if (dis[v][rev_count%2] < c) continue;
        for (const auto& u:graph[v]) {
            auto new_cost {c+1};
            auto new_rev_count {rev_count};
            if (rev_count%2 == 1) {
                new_cost += x;
                ++new_rev_count;
            }
            if (new_cost < dis[u][new_rev_count%2]) {
                dis[u][new_rev_count%2] = new_cost;
                pq.push({u, new_cost, new_rev_count});
            }
        }
        for (const auto& u:rev_graph[v]) {
            auto new_cost {c+1};
            auto new_rev_count {rev_count};
            if (rev_count%2 == 0) {
                new_cost += x;
                ++new_rev_count;
            }
            if (new_cost < dis[u][new_rev_count%2]) {
                dis[u][new_rev_count%2] = new_cost;
                pq.push({u, new_cost, new_rev_count});
            }
        }
    }

    cout << min(dis[n-1][0], dis[n-1][1]) << '\n';
    return 0;
}

