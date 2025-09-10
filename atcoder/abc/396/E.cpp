#include <iostream>
#include <vector>
 
using namespace std;

// main obstacle was to choose starting value for each component.
// each k-th bit can be computed independently, they don't depend on each other.
// so if k-th bit is 1, sum1 += (1<<k) or 0 depending on each consecutive node.
// so if k-th bit is 0, sum2 += 0 or (1<<k) depending on each consecutive node. (basically all k-th bit in each node in component is flipped)
// make k-th bit for starting value 0 or 1 depending on which results in lesser sum.
// do this for all bits from 0-th up to 30-th.
// for each component optimal starting value will be chosen.

struct node {
    int v{};
    int w{};
};

bool dfs(int i, const vector<vector<node>>& graph, vector<bool>& vis, vector<int>& v, vector<int>& to_clear)
{
    if (vis[i]) return true;
    vis[i] = true;
    to_clear.emplace_back(i);
    for (const auto& [j, w]:graph[i]) {
        if (!vis[j]) {
            v[j] = w^v[i];
            auto ok {dfs(j, graph, vis, v, to_clear)};
            if (!ok) return false;
        }
        else if ((v[j]^v[i]) != w) {
            return false;
        }
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    vector<vector<node>> graph(n);
    bool ok {true};
    for (int i{}; i<m; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        --x[i]; --y[i];
        if (x[i] == y[i]) {
            if (z[i] != 0) {
                ok = false;
            }
            continue;
        }
        graph[x[i]].push_back({y[i], z[i]});
        graph[y[i]].push_back({x[i], z[i]});
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> A(n);
    vector<int> tmp(n);
    vector<bool> vis(n);
    vector<int> component; component.reserve(n);

    for (int i{}; i<n; ++i) {
        if (!vis[i]) {
            int starting_value {};
            for (int k{}; k<=30; ++k) {
                tmp[i] = (1<<k);
                if (!dfs(i, graph, vis, tmp, component)) {
                    ok = false;
                    break;
                }
                int64_t sm1 {};
                int64_t sm2 {};
                for (const auto& j:component) {
                    sm1 += ((1<<k) & tmp[j]) == 0 ? 0 : (1<<k);
                    sm2 += ((1<<k) & tmp[j]) == 0 ? (1<<k) : 0;
                    vis[j] = false;
                }
                component.clear();
                if (sm1 < sm2) { // k-th bit in starting value in this component is 1. Otherwise 0.
                    starting_value += (1<<k);
                }
            }
            if (!ok) break;

            A[i] = starting_value;
            if (!dfs(i, graph, vis, A, component)) {
                ok = false;
                break;
            }
            component.clear();
        }
        if (!ok) break;
    }

    if (!ok) cout << -1 << '\n';
    else {
        for (const auto& i:A) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}
