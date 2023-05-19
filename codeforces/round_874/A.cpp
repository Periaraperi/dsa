#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        set<string> st;
        for (int i=0; i<s.size()-1; ++i) {
            string x; x.push_back(s[i]); x.push_back(s[i+1]);
            st.insert(x);
        }
        cout << st.size() << '\n';
    }
    return 0;
}

