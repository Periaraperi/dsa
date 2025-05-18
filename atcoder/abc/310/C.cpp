#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n; cin >> n;
		vector<string> v(n);
		set<string> st;
		for (int i=0; i<n; ++i) {
			cin >> v[i];
			if (st.find(v[i])!=st.end()) continue;
			auto tmp = v[i];
			reverse(tmp.begin(),tmp.end());
			if (st.find(tmp)==st.end()) {
				st.insert(v[i]);
			}
		}
		cout << st.size() << '\n';
    }
    return 0;
}

