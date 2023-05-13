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
        int a = 0;
        int b = 0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='A') ++a;
            else ++b;
        }
        if (a>b)
            cout << "A\n";
        else if (a<b) 
            cout << "T\n";
        else {
            if (s[n-1]=='A') cout << "T\n";
            else cout << "A\n";
        }

    }
    return 0;
}

