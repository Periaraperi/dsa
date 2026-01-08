#include <iostream>
#include <queue>
#include <vector>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    
    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<int>> parents(n);

    for (int i{}; i<m; ++i) {
        int a, b; std::cin >> a >> b; --a; --b;
        graph[a].emplace_back(b);
        parents[b].emplace_back(a);
    }

    std::vector<bool> reachable(n);

    int Q; std::cin >> Q;
    while (Q--) {
        int op, v; std::cin >> op >> v; --v;
        if (op == 1) {
            std::queue<int> q;
            q.push(v);
            while (!q.empty()) {
                const auto u {q.front()}; q.pop();
                if (reachable[u]) continue;
                reachable[u] = true;
                for (const auto& k:parents[u]) {
                    if (!reachable[k]) {
                        q.push(k);
                    }
                }
            }
        }
        else {
            if (reachable[v]) {
                std::cout << "Yes\n";
            }
            else {
                std::cout << "No\n";
            }
        }
    }
    return 0;
}

