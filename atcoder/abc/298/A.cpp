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
        int good = 0;
        int poor = 0;
        for (auto ch:s) {
            if (ch=='o') ++good;
            if (ch=='x') ++poor;
        }
        if (poor==0 && good>0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

