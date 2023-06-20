#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
		int n; cin >> n;
		int64_t sm = 0;
		vector<int64_t> v(n);
		for (int i=0; i<n; ++i) cin >> v[i];
		int cnt = 0;
		for (int i=0; i<n; ++i) {
			if (v[i]<0) {
				while (i<n && v[i]<=0) {
					v[i] *= (-1);
					++i;
				}
				++cnt;
			}
		}
		sm = std::accumulate(v.begin(),v.end(),0LL);
		cout << sm << " " << cnt << '\n';
    }
    return 0;
}

