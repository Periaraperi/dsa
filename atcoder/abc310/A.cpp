#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n,p,q; cin >> n >> p >> q;
		int mn = 1e9;
		for (int i=0; i<n; ++i) {
			int a; cin >> a;
			mn = min(mn,a);
		}
		cout << min(mn+q,p) << '\n';
    }
    return 0;
}

