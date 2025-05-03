#include <iostream>
#include <limits>
#include <vector>
 
using namespace std;

int64_t calculate(const vector<int>& v, const vector<int64_t>& costs, const vector<vector<int>>& graph, const int m)
{
    vector<int> animals_seen(m, 0);
    
    int64_t total_cost {};
    const int N {(int)v.size()};
    for (int i{}; i<N; ++i) {
        if (v[i] == 0) continue;
        total_cost += v[i]*costs[i];
        for (const auto& animal:graph[i]) {
            animals_seen[animal] += v[i];
        }
    }

    for (const auto& a:animals_seen) {
        if (a < 2) {
            return numeric_limits<int64_t>::max();
        }
    }

    return total_cost;
}

void recurse(int i, vector<int>& v, const vector<int64_t>& costs, const vector<vector<int>>& graph, int64_t& ans, const int m)
{
    const int N {(int)v.size()};
    if (i == N) {
        ans = min(ans, calculate(v, costs, graph, m));
        return;
    }
    
    for (int j=0; j<3; ++j) {
        v[i] = j;
        recurse(i+1, v, costs, graph, ans, m);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vector<int64_t> costs(N);
    for (auto& c:costs) cin >> c;

    vector<vector<int>> graph(N);
    for (int i{}; i<M; ++i) {
        int K; cin >> K;
        while (K--) {
            int zoo; cin >> zoo; --zoo;
            graph[zoo].push_back(i);
        }
    }

    vector<int> v(N, 0);
    int64_t ans{numeric_limits<int64_t>::max()};
    recurse(0, v, costs, graph, ans, M);
    cout << ans << '\n';

    return 0;
}

