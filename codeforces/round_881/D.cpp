#include <bits/stdc++.h>
 
using namespace std;
 
void dfs(int v, const vector<vector<int>>& tree, vector<bool>& vis, int p, vector<int64_t>& dp)
{
	if (vis[v]) return;
	vis[v] = true;
	if (tree[v].size()==1 && p==tree[v][0]) {
		dp[v] = 1;
		++dp[p];
		return;
	}
	for (auto u:tree[v]) {
		dfs(u,tree,vis,v,dp);
	}
	if (p!=-1)
		dp[p] += dp[v];
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
		int n; cin >> n;
		vector<vector<int>> tree(n);
		vector<bool> vis(n,false);
		vector<int64_t> dp(n,0LL);
		for (int i=0; i<n-1; ++i) {
            int a,b; cin >> a >> b;
            --a; --b;
            tree[a].push_back(b);
            tree[b].push_back(a);
		}
		dfs(0,tree,vis,-1,dp);
		int q; cin >> q;
		while (q--) {
			int x,y; cin >> x >> y;
			--x; --y;
			cout << dp[x]*dp[y] << '\n';
		}
    }
    return 0;
}
