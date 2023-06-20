#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
		int64_t n; cin >> n;
		int64_t sm = 0;
		while (n>0) {
			sm += n;
			n /= 2;
		}
		cout << sm << '\n';
    }
    return 0;
}

