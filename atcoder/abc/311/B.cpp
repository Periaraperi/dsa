#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n,m; cin >> n >> m;
		vector<string> v(n);
		for (auto& i:v) cin >> i;
		
		int ans = 0;
		int cnt = 0;

		for (int i=0; i<m; ++i) {
			bool ok = true;
			for (int j=0; j<n; ++j) {
				if (v[j][i]!='o') {
					ok = false;
					break;
				}
			}
			if (ok) {
				++cnt;
			} else {
				ans = max(ans,cnt);
				cnt = 0;
			}
		}
		ans = max (ans,cnt);
		cout << ans << '\n';
    }
    return 0;
}

