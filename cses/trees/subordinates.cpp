#include <iostream>
#include <vector>
 
using namespace std;

void dfs(int v, const vector<vector<int>>& tree, vector<int>& subs)
{
    if (tree[v].empty()) {
        subs[v] = 0;
        return;
    }
    int s {};
    for (const auto& u:tree[v]) {
        dfs(u, tree, subs);
        s += subs[u]+1;
    }
    subs[v] = s;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i{1}; i<=n-1; ++i) {
        int a; cin >> a;
        --a;
        tree[a].emplace_back(i);
    }

    vector<int> subs(n, 0);
    dfs(0, tree, subs);

    for (int i{}; i<n; ++i) {
        cout << subs[i] << " ";
    }
    cout << '\n';

    return 0;
}

