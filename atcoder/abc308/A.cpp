#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		bool ok = 1;
		vector<int> v(8);
		for (int i=0; i<8; ++i) {
			cin >> v[i];
		}
		for (int i=0; i<8; ++i) {
			if (v[i]<100 || v[i]>675 || v[i]%25!=0) {
				ok = false;
				break;
			}
		}
		for (int i=1; i<8; ++i) {
			if (v[i-1]>v[i]) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "Yes\n";
		else	cout << "No\n";
    }
    return 0;
}

