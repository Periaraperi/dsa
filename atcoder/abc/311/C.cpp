#include <bits/stdc++.h>
 
using namespace std;
 
int cycle_start = -1;
int cycle_end = -1;
bool dfs(int v, const vector<vector<int>>& graph, vector<int>& color, vector<int>& parent)
{
	color[v] = 1;
	for (auto i:graph[v]) {
		if (color[i]==0) {
			parent[i] = v;
			if (dfs(i,graph,color,parent)) {
				return true;
			}
		} else if (color[i]==1) {
			cycle_start = i;
			cycle_end = v;
			return true;
		}
	}

	color[v] = 2;
	return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n; cin >> n;
		vector<vector<int>> graph(n);
		for (int i=0; i<n; ++i) {
			int a; cin >> a;
			--a;
			graph[i].push_back(a);
		}
		
		vector<int> parent(n,-1);
		vector<int> color(n,0);
		bool b = false;
		for (int i=0; i<n; ++i) {
			if (color[i]==0) {
				int b = dfs(i,graph,color,parent);
				if (b) break;
			}
		}
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v=cycle_end; v!=cycle_start; v=parent[v])
			cycle.push_back(v);
		reverse(cycle.begin(), cycle.end());
		cout << cycle.size() << '\n';
		for (auto i:cycle) {
			cout << i+1 << ' ';
		}
		cout << '\n';
    }
    return 0;
}

