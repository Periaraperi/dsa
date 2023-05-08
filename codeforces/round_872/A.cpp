#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        set<char> st;
        for (int i=0; i<n; ++i) {
            st.insert(s[i]);
        }
        if (st.size()==1) {
            cout << -1 << '\n';
            continue;
        }
        string x = s;
        reverse(x.begin(),x.end());
        if (x==s) {
            cout << n-1 << '\n';
        } else {
            cout << n << '\n';
        }
    }
    return 0;
}

