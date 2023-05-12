#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        string s; cin >> s;
        vector<int> freq(26);
        for (auto ch:s) ++freq[ch-'a'];
        set<char> st;
        for (auto ch:s) {
            if (freq[ch-'a']>1) st.insert(ch);
        }
        if (st.size()>=2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

