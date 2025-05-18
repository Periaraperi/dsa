#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = (int) s.size();
        array<int,2> a,b;
        int k = 0;
        int j = 0;
        int x = 0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='B') {
                a[j] = i; 
                ++j;
            }
            if (s[i]=='K') k = i;
            if (s[i]=='R') {
                b[x] = i;
                ++x;
            }
        }
        if ((a[0]%2!=a[1]%2) && (b[0]<k && k<b[1])) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

