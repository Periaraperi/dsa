#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n,m; cin >> n >> m;
		vector<string> v(n), vv(m);
		for (auto& str:v) cin >> str;
		for (auto& str:vv) cin >> str;
		vector<int> sc(m+1);
		for (auto& i:sc) cin >> i;

		auto ans = 0LL;
		for (int i=0; i<n; ++i) {
			bool is = false;
			for (int j=0; j<m; ++j) {
				if (v[i]==vv[j]) {
					ans += sc[j+1];
					is = true;
					break;
				}
			}
			if (!is) ans += sc[0];
		}
		cout << ans << '\n';

    }
    return 0;
}

