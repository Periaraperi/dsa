#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (auto& i:v) {
			cin >> i;
		}
		sort(v.begin(),v.end());
		int sm = 0;
		int l = 0;
		int r = n-1;
		while (l<=r) {
			sm += (v[r]-v[l]);
			--r;
			++l;
		}
		cout << sm << '\n';
    }
    return 0;
}

