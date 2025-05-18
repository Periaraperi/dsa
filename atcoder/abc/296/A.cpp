#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ok = true;
        for (int i=0; i<n-1; ++i) {
            if (s[i]==s[i+1]) {
                ok = false;
                break;
            }
        }
        cout << (ok? "Yes\n":"No\n");
    }
    return 0;
}

