#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n,m; cin >> n >> m;
		vector<int> p(n);
		vector<vector<int>> vv(n);
		vector<vector<int>> bb(n,vector<int>(m+1,0));
		for (int i=0; i<n; ++i) {
			cin >> p[i];
			int c; cin >> c;
			vv[i].resize(c);
			for (int j=0; j<c; ++j) {
				cin >> vv[i][j];
				int x = vv[i][j];
				bb[i][x] = 1;
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (i==j) continue;
				if (p[i]>=p[j]) {
					bool ok = true;
					for (auto& ff:vv[i]) {
						if (bb[j][ff]==0) {
							ok = false;
							break;
						}
					}
					if (ok) {
						if (p[i]==p[j]) {
							for (auto& ff:vv[j]) {
								if (bb[i][ff]==0) {
									cout << "Yes\n";
									return 0;
								}
							}
						} else {
							cout << "Yes\n";
							return 0;
						}
					}
				}
			}
		}
		cout << "No\n";

    }
    return 0;
}

