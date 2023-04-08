#include <bits/stdc++.h>
    
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 1; cin >> tt;
    while (tt--) {
        stack<char> stk;
        int n; cin >> n;
        string s; cin >> s;
        for (auto& ch:s) ch = std::tolower(ch);
        set<char> st;
        string x;

        int i = 0;
        while (i<s.size()) {
            x += s[i];
            while (i+1<s.size() && s[i]==s[i+1]) ++i;
            ++i;
        }

        
        if (x=="meow") cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}