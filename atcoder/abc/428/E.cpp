#include <iostream>
#include <vector>
 
using namespace std;

void dfs(int v, int p, vector<vector<int>>& tree, vector<bool>& vis, vector<int>& dis)
{
    if (vis[v]) return;
    vis[v] = true;
    if (p != -1) dis[v] = dis[p]+1;
    for (const auto& u:tree[v]) {
        dfs(u, v, tree, vis, dis);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i{}; i<n-1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> dis(n, 0);
    dfs(0, -1, tree, vis, dis);
    int x {};
    {
        int mx {};
        vector<int> a;
        for (int i{}; i<n; ++i) {
            mx = max(mx, dis[i]);
        }
        for (int i{}; i<n; ++i) {
            if (dis[i] == mx) a.push_back(i);
        }
        x = a.back();
    }
    vis = vector<bool>(n, false);
    dis = vector<int>(n, 0);
    dfs(x, -1, tree, vis, dis);
    int y {};
    {
        int mx {};
        vector<int> a;
        for (int i{}; i<n; ++i) {
            mx = max(mx, dis[i]);
        }
        for (int i{}; i<n; ++i) {
            if (dis[i] == mx) a.push_back(i);
        }
        y = a.back();
    }
    
    vis = vector<bool>(n, false);
    vector<int> dis_x(n, 0);
    vector<int> dis_y(n, 0);
    dfs(x, -1, tree, vis, dis_x);

    vis = vector<bool>(n, false);
    dfs(y, -1, tree, vis, dis_y);

    for (int i{}; i<n; ++i) {
        if (dis_x[i] == dis_y[i]) {
            cout << max(x, y)+1 << '\n';
        }
        else if (dis_x[i] > dis_y[i]) {
            cout << x+1 << '\n';
        }
        else {
            cout << y+1 << '\n';
        }
    }

    return 0;
}
