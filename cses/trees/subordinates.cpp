#include <iostream>
#include <vector>

using namespace std;

int dfs(int v, const vector<vector<int>>& tree, vector<int>& ans)
{
    if(tree[v].size()==0) return 1;
    for(auto n:tree[v]) {
        ans[v] += dfs(n,tree,ans);
    }
    return ans[v]+1;
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> tree(n+1);
    for(int i=1; i<n; ++i) {
        int empl; cin >> empl;
        tree[empl].push_back(i+1);
    }
    vector<int> ans(n+1);
    dfs(1,tree,ans);
    for(int i=1; i<=n; ++i)
        cout << ans[i] << " ";

    return 0;
}