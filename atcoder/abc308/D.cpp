#include <bits/stdc++.h>
 
using namespace std;
 
struct Item {
	int i,j;
	int sz;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t= 1; //cin >> t;
    while (t--) {
		int n,m; cin >> n >> m;
		vector<vector<char>> grid(n,vector<char>(m));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				cin >> grid[i][j];
			}
		}

		string snuke = "snuke";
		vector<vector<bool>> vis(n,vector<bool>(m,false));
		queue<Item> q;
		if (grid[0][0]!='s') {
			cout << "No\n";
			return 0;
		}
		q.push({0,0,0});

		vector<int> di = {1,-1,0,0};
		vector<int> dj = {0,0,1,-1};

		while (!q.empty()) {
			auto [i,j,sz] = q.front();
			q.pop();
			if (vis[i][j]) continue;
			vis[i][j] = true;
			
			for (int d=0; d<4; ++d) {
				int new_i = i+di[d];
				int new_j = j+dj[d];
				if (new_i>=0 && new_i<n && new_j>=0 && new_j<m && !vis[new_i][new_j]) {
					if (snuke[(sz+1)%5]==grid[new_i][new_j]) {
						q.push({new_i,new_j,sz+1});
						//cout << "deb: " << new_i << " " << new_j << " " << sz+1 << '\n';
					}
				}
			}
		}
		if (vis[n-1][m-1]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}

    }
    return 0;
}

