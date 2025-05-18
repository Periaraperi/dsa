#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        string a,b; cin >> a >> b;
        bool ok = true;
        for (int i=0; i<n; ++i) {
            if (!(a[i]==b[i] || (a[i]=='1' && b[i]=='l') || (b[i]=='1' && a[i]=='l') || (a[i]=='0' && b[i]=='o') || (b[i]=='0' && a[i]=='o'))) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

