#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        string s; cin >> s;
        string x = "codeforces";
        int cnt = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i]!=x[i]) ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}

