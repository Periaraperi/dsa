#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt = 0;
		set<char> st;
		for (auto ch:s) {
			if (st.size()==3) {
				break;
			}
			++cnt;
			st.insert(ch);
		}
		cout << cnt << '\n';
    }
    return 0;
}

